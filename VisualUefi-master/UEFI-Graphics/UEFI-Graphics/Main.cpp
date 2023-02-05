#include <Uefi.h>
#include "General.h"
#include "Graphics/Screen.hpp"
#include "Graphics/Shapes/Mouse.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
#include "Graphics/Shapes/Circle.hpp"
extern "C" {
#include <Library/UefiLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/ShellLib.h>
#include <Guid/SmBios.h>
}
#include "Graphics/Graphics.hpp"
CAPI EFI_STATUS EFIAPI UefiUnload (IN EFI_HANDLE ImageHandle) { return 0; }

CAPI EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle,IN EFI_SYSTEM_TABLE* SystemTable){
	constexpr EFI_STATUS efi_status = EFI_SUCCESS;
    printf(L"Hello"); 
    
    Screen s(800, 600);
    
    Circle cir(50, 50, 50, Color::BLUE);
    s.Render(cir);
    
    return efi_status;
}

