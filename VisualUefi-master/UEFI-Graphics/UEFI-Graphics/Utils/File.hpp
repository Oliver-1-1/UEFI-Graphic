#pragma once
#include "../General.h"
class File{
public:
	File(const CHAR16* path);
	~File() = default;

	VOID* Read(UINTN* size);
	VOID Write(VOID* data, UINTN size); //This works half of the time. Do not use

	BOOLEAN Exists();

private:

	const CHAR16* path_;
	EFI_GUID info_id_ = EFI_FILE_INFO_ID;

};