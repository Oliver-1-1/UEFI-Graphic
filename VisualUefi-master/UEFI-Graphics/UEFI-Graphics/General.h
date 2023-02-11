#pragma once

#define CAPI extern "C"
#define printf(text) Print((const CHAR16*)text);

#include <IndustryStandard/SmBios.h>
#include <IndustryStandard/Usb.h>
#include <Protocol/SimplePointer.h>

CAPI{
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
}