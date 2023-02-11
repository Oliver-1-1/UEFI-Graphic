#include "Graphics.hpp"

VOID Graphics::Render() const {
	const auto status = gop_->Blt(gop_, blt_buffer_, ::EfiBltBufferToVideo, 0, 0, 0, 0, screen_x_size_, screen_y_size_, 0);
}

VOID Graphics::DrawRectangle(INTN x, INTN y, UINTN width, UINTN height, Color color) const {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			DrawPixel(x+i, y+j, color);
		}
	}

}

Graphics::Graphics(UINTN screen_x_size, UINTN screen_y_size) : oldx_(screen_x_size / 2), oldy_(screen_y_size / 2), screen_x_size_(screen_x_size), screen_y_size_(screen_y_size) {
	const EFI_STATUS st = gBS->LocateProtocol(&gEfiGraphicsOutputProtocolGuid, NULL, reinterpret_cast<void**>(&gop_));
	if (EFI_ERROR(st)) {
		printf(L"Could not find protocol graph.\n");
		return;
	}
	gop_->SetMode(gop_, GetProperGraphicsMode(screen_x_size, screen_y_size)); // Get the right mode for the right res. Its like settings on different resolutions.
	blt_buffer_ = new EFI_GRAPHICS_OUTPUT_BLT_PIXEL[screen_x_size * screen_y_size];
}

VOID Graphics::DrawPixel(INTN x, INTN y, Color color) const{
	if (x > screen_x_size_ || x < 0) {
		//printf(L"Too large writing buffer in DrawRectangle. X\n");
		return;
	}
	if (y > screen_y_size_ || y < 0) {
		//printf(L"Too large writing buffer in DrawRectangle. Y\n");
		return;
	}
	blt_buffer_[screen_x_size_ * y + x] = EFI_GRAPHICS_OUTPUT_BLT_PIXEL{ color.Get().Blue, color.Get().Green, color.Get().Red, color.Get().Reserved };
}

bool Graphics::IsProperGraphicsMode(const EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* mode_info, const UINTN horizontal_resolution, const UINTN vertical_resolution) {
	return	mode_info->HorizontalResolution == horizontal_resolution && mode_info->PixelFormat == PixelBlueGreenRedReserved8BitPerColor &&
		mode_info->VerticalResolution == vertical_resolution;
}

UINT32 Graphics::GetProperGraphicsMode(const UINTN horizontal_resolution, const UINTN vertical_resolution) const {
	for (UINT32 i = 0; i < gop_->Mode->MaxMode; i++) {
		EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* mode_info;
		UINTN size_of_mode_info;

		const auto status = gop_->QueryMode(gop_, i, (UINTN*)&size_of_mode_info, &mode_info);

		if (IsProperGraphicsMode(mode_info, horizontal_resolution, vertical_resolution)) {
			return i;
		}
	}
	printf(L"Could not find graph mode.\n");

	return 0;
}