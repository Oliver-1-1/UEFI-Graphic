#pragma once
#include "../General.h"

//Does not automatically create the file if it does not exist!
class File{
public:
	File(const CHAR16* path);
	~File() = default;

	CHAR8* Read(UINTN* size);
	CHAR8* Read();
	CHAR16* ReadWide(UINTN* size);
	CHAR16* ReadWide();
	VOID Write(CHAR8* data, UINTN size);
	VOID WriteWide(CHAR16* data, UINTN size);

private:
	VOID* ReadData(UINTN* size);
	VOID WriteData(VOID* data, UINTN size); //This works half of the time. Do not use
	const CHAR16* path_;
	EFI_GUID info_id_ = EFI_FILE_INFO_ID;

};