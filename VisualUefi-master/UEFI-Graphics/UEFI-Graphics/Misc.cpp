extern "C" {
#include <Uefi.h>
#include <Library/MemoryAllocationLib.h>
}
// Remove exceptipon in settings for no compile error

void* operator new(const unsigned long long size){
	return AllocateZeroPool(size);
}

void* operator new[](const unsigned long long size){
	return AllocateZeroPool(size);
}

void operator delete(void* buf){
	FreePool(buf);
}

void operator delete[](void* buf){
	FreePool(buf);
}

void operator delete(void* buf, const unsigned long long){
	FreePool(buf);
}

void operator delete[](void* buf, const unsigned long long){
	FreePool(buf);
}