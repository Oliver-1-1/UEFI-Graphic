#pragma once
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
class Color{
public:
	Color(CHAR8 r, CHAR8 g, CHAR8 b, CHAR8 a) {
		col_.Red = r;
		col_.Green = g;
		col_.Blue = b;
		col_.Reserved = a; // I dont know what this does
	}

	static enum Types {
		BLACK,
		WHITE,
		BLUE,
		RED,
		GREEN
	};

	Color(Types color) { // Its not RBGA, its BGR Reserved
		if (color == BLACK) {
			EFI_GRAPHICS_OUTPUT_BLT_PIXEL c = {0,0,0,0};
			col_ = c;
		}
		if (color == WHITE) {
			EFI_GRAPHICS_OUTPUT_BLT_PIXEL c = { 255,255,255,0 };
			col_ = c;
		}
		if (color == BLUE) {
			EFI_GRAPHICS_OUTPUT_BLT_PIXEL c = { 255,0,0,0 };
			col_ = c;
		}
		if (color == RED) {
			EFI_GRAPHICS_OUTPUT_BLT_PIXEL c = { 0,0,255,0 };
			col_ = c;
		}
		if (color == GREEN) {
			EFI_GRAPHICS_OUTPUT_BLT_PIXEL c = { 0,255,0,0 };
			col_ = c;
		}
	}

	EFI_GRAPHICS_OUTPUT_BLT_PIXEL Get() { return col_; }
private:
	EFI_GRAPHICS_OUTPUT_BLT_PIXEL col_;

};