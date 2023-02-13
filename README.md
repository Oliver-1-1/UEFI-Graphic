# UEFI-Graphic - Simpel usage of graphic in UEFI.
UEFI-Graphic brings graphics to UEFI in a simple way and it is written in C++. 
Visual-efi is used for development environment

The project will support:
1. Basic shapes                // Done
2. Basic text                  // Done
3. Basic mouse support         // Done
4. Basic file managment        // Done
5. Basic transform of shapes   // Done.
6. Basic internet connectivity // Not started

Might want to add rotation to transform. The issue is i cant seem to get float support to work.
## Usage

 It has a very simple usage and abstracts all the protocol and buffer searching that is essential for UEFI.
 This shows a very simple use case
```
CAPI EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle,IN EFI_SYSTEM_TABLE* SystemTable){
  constexpr EFI_STATUS efi_status = EFI_SUCCESS;
    
  Text t(50, 50, 2, Color::WHITE, (CHAR8*)"UEFI is fun but a pain in the ass.", (CHAR16*) L"font.fnt");
  Text t1(175, 100, 1, Color::WHITE, (CHAR8*)"LMAO what is this. Zepta.....", (CHAR16*)L"font.fnt");

  Circle c(500, 500, 50, Color::RED);
  Rectangle r(350, 500, 50, 50, Color::GREEN);

  Screen s(800, 600);
 
  s.ClearBackground(Color::BLUE);
  s.Render(t);
  s.Render(c);
  s.Render(r);
  s.Render(t1);

  return efi_status
}
```

## Images

This picture shows the result of above code. It all looks like it came from the 90s but it mostly has to do with the font.

![](https://cdn.discordapp.com/attachments/865269282903162913/1073791181814779985/image.png)
