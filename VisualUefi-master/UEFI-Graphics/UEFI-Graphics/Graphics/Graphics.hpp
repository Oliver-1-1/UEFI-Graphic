#pragma once
#include "Color.hpp"
#include "../General.h"

extern "C" {
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>   
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/SynchronizationLib.h>
#include <Library/ShellLib.h>
#include <Guid/SmBios.h>
#include <Library/UefiUsbLib.h>
#include <Protocol/GraphicsOutput.h>
}

class Graphics {
public:
	Graphics(UINT32 screen_x_size, UINT32 screen_y_size);
	~Graphics() {
		delete blt_buffer_;
	}

	VOID DrawRectangle(UINTN x, UINTN y, UINTN width, UINTN height, Color color) const;
	VOID DrawPixel(UINTN x, UINTN y, Color color) const;
	VOID Render() const;

private:
	EFI_GRAPHICS_OUTPUT_BLT_PIXEL mou_[8][8];
	int oldx_, oldy_;
	EFI_GRAPHICS_OUTPUT_PROTOCOL* gop_{};
	EFI_GRAPHICS_OUTPUT_BLT_PIXEL* blt_buffer_;

	UINT32 screen_x_size_, screen_y_size_;
	UINT32 GetProperGraphicsMode(const UINTN horizontal_resolution, const UINTN vertical_resolution) const;
	static bool IsProperGraphicsMode(const EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* mode_info, const UINTN horizontal_resolution, const UINTN vertical_resolution);
};

