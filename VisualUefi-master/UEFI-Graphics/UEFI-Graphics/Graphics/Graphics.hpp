#pragma once
#include "Color.hpp"
#include "../General.h"

extern "C" {
	#include <Uefi.h>
	#include <Protocol/GraphicsOutput.h>
}

struct Point{
	int x;
	int y;
};

class Graphics {
public:
	Graphics(UINTN screen_x_size, UINTN screen_y_size);
	~Graphics() {
		delete blt_buffer_;
	}

	VOID DrawRectangle(INTN x, INTN y, UINTN width, UINTN height, Color color) const;
	VOID DrawPixel(INTN x, INTN y, Color color) const;
	VOID Render() const;

private:
	EFI_GRAPHICS_OUTPUT_BLT_PIXEL mou_[8][8];
	int oldx_, oldy_;
	EFI_GRAPHICS_OUTPUT_PROTOCOL* gop_{};
	EFI_GRAPHICS_OUTPUT_BLT_PIXEL* blt_buffer_;

	UINTN screen_x_size_, screen_y_size_;
	UINT32 GetProperGraphicsMode(const UINTN horizontal_resolution, const UINTN vertical_resolution) const;
	static bool IsProperGraphicsMode(const EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* mode_info, const UINTN horizontal_resolution, const UINTN vertical_resolution);
};

