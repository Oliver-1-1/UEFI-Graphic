#include <Uefi.h>
#include "General.hpp"
#include "Graphics/Screen.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
#include "Utils/File.hpp"
#include "Graphics/Shapes/Circle.hpp"
#include "Graphics/Shapes/Text.hpp"
#include "Graphics/Graphics.hpp"
#include "Utils/Mouse.hpp"
//AsciiPrint() could be used whole proj.

#define DEBUG

CAPI EFI_STATUS EFIAPI UefiUnload (IN EFI_HANDLE ImageHandle) { return 0; }

CAPI EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle,IN EFI_SYSTEM_TABLE* SystemTable){
	constexpr EFI_STATUS efi_status = EFI_SUCCESS;

    Text t(50, 50, 2, Color::BLACK, (CHAR8*)"UEFI is fun but a pain in the ass.", (CHAR16*) L"font.fnt");
    Text t1(175, 100, 1, Color::BLACK, (CHAR8*)"LMAO what is this. Zepta.....", (CHAR16*)L"font.fnt");

    Circle c(500, 500, 50, Color::RED);
    Rectangle r(400, 300, 5, 5, Color::GREEN);

    Screen s(800, 600);

    Mouse m(800, 600);

    File f((CHAR16*)L"Download.txt");
    f.Write((CHAR8*)"Hello1", 7); // 1 byte for end line char \0

	//s.ClearBackground(Color::BLACK);
	//s.Render(t);
	//s.Render(c);
	//s.Render(r);
	//s.Render(t1);
    for (int i = 0; i < 999999; i++) {
        s.Render(c);
        s.Render(t);
        s.Render(t1);
        s.Render(r);
        gBS->Stall(10000);
        //gST->ConOut->ClearScreen(gST->ConOut);

    }
    
    return efi_status;
}

