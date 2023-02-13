#pragma once
#include "../General.h"

class Mouse{
public:
	Mouse(UINTN screen_width, UINTN screen_height);
	~Mouse() = default;

	static struct Point{
		INT32 x;
		INT32 y;
	};
	
	bool GetLButton() const;
	bool GetRButton() const;
	Point GetPosition();

private:
	UINTN screen_width_;
	UINTN screen_height_;

	bool l_button_;
	bool r_button_;

	Point real_pos_;

	EFI_SIMPLE_POINTER_PROTOCOL* mouse_ = nullptr;
	EFI_SIMPLE_POINTER_STATE     state_;

	EFI_GUID g_efi_simple_pointer_protocol_guid_ = { 0x31878C87, 0xB75,0x11D5,
	{ 0x9A, 0x4F,0x0, 0x90, 0x27, 0x3F,0xC1, 0x4D } };


};

