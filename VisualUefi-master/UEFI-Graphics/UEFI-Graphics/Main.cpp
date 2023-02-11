#include <Uefi.h>
#include "General.h"
#include "Graphics/Screen.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
#include "Utils/File.hpp"
#include "Graphics/Shapes/Circle.hpp"
#include "Graphics/Shapes/Text.hpp"
#include "Graphics/Graphics.hpp"

CAPI EFI_STATUS EFIAPI UefiUnload (IN EFI_HANDLE ImageHandle) { return 0; }

CAPI EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle,IN EFI_SYSTEM_TABLE* SystemTable){
	constexpr EFI_STATUS efi_status = EFI_SUCCESS;
    

    Text t(50, 50, 2, Color::WHITE, (CHAR8*)"UEFI is fun but a pain in the ass.", (CHAR16*) L"font.fnt");
    Text t1(175, 100, 1, Color::WHITE, (CHAR8*)"LMAO what is this. Zepta.....", (CHAR16*)L"font.fnt");

    Circle c(500, 500, 50, Color::RED);
    Rectangle r(350, 500, 50, 50, Color::GREEN);

    Screen s(800, 600);

 
    for(int i = 0; i < 9999999; i++) {
        s.ClearBackground(Color::BLUE);
        s.Render(t);
        s.Render(c);
        s.Render(r);
        s.Render(t1);

    }
    return efi_status;
}

