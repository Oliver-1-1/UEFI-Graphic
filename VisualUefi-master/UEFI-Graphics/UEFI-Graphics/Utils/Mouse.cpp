#include "Mouse.hpp"

Mouse::Mouse(UINTN screen_width, UINTN screen_height){

	//Initiate the two buttons to false since we can't predict that buttons are pressed.
	l_button_ = false;
	r_button_ = false;

	screen_width_ = screen_width;
	screen_height_ = screen_height;

	//Initiate the mouse cursor position to middle of the screen.
	real_pos_.x = screen_width / 2;
	real_pos_.y = screen_height / 2;

	//Enable cursor. I do not know if this is needed.
	gST->ConOut->EnableCursor(gST->ConOut, true);

	//Locate the mouse protocol so we can receive the struct
	EFI_STATUS status = gBS->LocateProtocol(&g_efi_simple_pointer_protocol_guid_, NULL, (VOID**)&mouse_);

	//If left button or right button = false then it is not supported
	if(EFI_ERROR(status) || !(mouse_->Mode->LeftButton && mouse_->Mode->RightButton)){
		return;
	}

	//Ignore Z since this project is 2D
	const UINT64 res_x = mouse_->Mode->ResolutionX;
	const UINT64 res_y = mouse_->Mode->ResolutionY;

	if(!(res_x && res_y)){
		return;
	}
}

bool Mouse::GetLButton() const{
	return l_button_;
}

bool Mouse::GetRButton() const{
	return r_button_;
}

Mouse::Point Mouse::GetPosition(){
	EFI_EVENT events;
	UINTN index;
	EFI_STATUS status = gBS->WaitForEvent(2, &events, &index);

	if(EFI_ERROR(status)){
		return real_pos_;
	}

	if (index == 0) {
		status = mouse_->GetState(mouse_, &state_);

		// Get delta from mouse
		const Point pos = {state_.RelativeMovementX, state_.RelativeMovementY};

		// Get the state of the mouse buttons
		l_button_ = state_.LeftButton;
		r_button_ = state_.RightButton;

		//Clamp to screen width
		if ((real_pos_.x + (pos.x / screen_width_)) >= screen_width_ || (real_pos_.x + (pos.x / screen_width_)) <= 0) {
			return real_pos_;
		}
		//Clamp to screen height
		if ((real_pos_.y + (pos.y / screen_height_)) >= screen_height_ || (real_pos_.y + (pos.y / screen_height_)) <= 0) {
			return real_pos_;
		}

		//Update the actual cursor position from the mouse delta received.
		real_pos_.x += (pos.x / screen_width_);
		real_pos_.y += (pos.y / screen_height_);
	}

	return real_pos_;
}
