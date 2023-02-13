#pragma once
#include <Uefi.h>

extern "C" const UINT8 _gDriverUnloadImageCount = 1;
extern "C" const UINT32 _gUefiDriverRevision = 0x200;
extern "C" const UINT32 _gDxeRevision = 0x200;

//Add in vshack.h aswell
extern "C" CHAR8* gEfiCallerBaseName = (CHAR8*)"Zepta";
