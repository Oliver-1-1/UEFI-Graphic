#include "File.hpp"

File::File(const CHAR16* path){
	path_ = path;

}

VOID* File::ReadData(UINTN* size){
	EFI_GUID guid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
	EFI_HANDLE* handles = nullptr;
	UINTN count = 0;
	VOID* buffer;

	//Get buffer with handles.
	if (EFI_ERROR(gBS->LocateHandleBuffer(ByProtocol, &guid, NULL, &count, &handles)))
		return nullptr;

	EFI_FILE_PROTOCOL* file = nullptr, *root = nullptr;

	//Loop through all handles and check if we are able to open path
	for (UINTN i = 0; i < count; i++) {
		EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* fs = nullptr;
		if (EFI_ERROR(gBS->HandleProtocol(handles[i], &guid, reinterpret_cast<void**>(&fs))))
			continue;

		if (EFI_ERROR(fs->OpenVolume(fs, &root)))
			continue;

		if (!EFI_ERROR(root->Open(root, &file, const_cast<CHAR16*>(path_), EFI_FILE_MODE_READ, EFI_FILE_READ_ONLY | EFI_FILE_HIDDEN | EFI_FILE_SYSTEM)))
			break;
	}

	if (file == nullptr)
		return nullptr;

	//Get Size of file.

	UINTN info_size = 0;
	if (file->GetInfo(file, &info_id_, &info_size, NULL) != EFI_BUFFER_TOO_SMALL)
		return nullptr;
	if (info_size == 0)
		return nullptr;

	//Get info
	const auto info = static_cast<EFI_FILE_INFO*>(AllocatePool(info_size));
	if(EFI_ERROR(file->GetInfo(file, &info_id_, (UINTN*)&info_size, info)))
		return nullptr;

	
	UINTN file_size = info->FileSize;
	for (UINTN i = info_size; i--;)
		reinterpret_cast<unsigned char*>(info)[i] = 0;

	FreePool(info);

	//Allocate memory to store the data.
	gBS->AllocatePool(EfiBootServicesData, file_size, &buffer);
	
	if (EFI_ERROR(file->Read(file, &file_size, buffer))) {
		root->Close(file);
		root->Close(root);
		FreePool(buffer);
		return nullptr;
	}

	root->Close(file);
	root->Close(root);
	*size = file_size;

	return buffer;

}

CHAR8* File::Read(UINTN* size){
	const auto wide_string_data = ReadWide(size);
	auto sting_data = new CHAR8[*size]; // Most likely memory leak here

	for(int i = 0; i < *size / 2; i++){
		sting_data[i] = static_cast<char>(wide_string_data[i]);
	}

	return sting_data;
}

CHAR8* File::Read(){
	UINTN size = 0;
	return Read(&size);
}

CHAR16* File::ReadWide(UINTN* size){
	VOID* data = ReadData(size);

	const auto wide_string_data = static_cast<CHAR16*>(data);

	return wide_string_data;
}

CHAR16* File::ReadWide(){
	UINTN size = 0;
	return ReadWide(&size);
}

VOID File::Write(CHAR8* data, UINTN size){
	auto wide_data = new CHAR16[size];

	for(int i = 0; i < size; i++){
		wide_data[i] = data[i];
	}

	WriteWide(wide_data, size * 2);

	delete[] wide_data;
}

VOID File::WriteWide(CHAR16* data, UINTN size){
	WriteData((VOID*)data, size);
}

VOID File::WriteData(VOID* data, UINTN size){
	EFI_GUID guid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
	EFI_HANDLE* handles = nullptr;
	UINTN count = 0;
	VOID* buffer;

	//Get buffer with handles.
	if (EFI_ERROR(gBS->LocateHandleBuffer(ByProtocol, &guid, NULL, &count, &handles)))
		return;

	EFI_FILE_PROTOCOL* file = nullptr, * root = nullptr;

	//Loop through all handles and check if we are able to open path
	for (UINTN i = 0; i < count; i++) {
		EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* fs = nullptr;
		if (EFI_ERROR(gBS->HandleProtocol(handles[i], &guid, reinterpret_cast<void**>(&fs))))
			continue;

		if (EFI_ERROR(fs->OpenVolume(fs, &root)))
			continue;

		if (!EFI_ERROR(root->Open(root, &file, const_cast<CHAR16*>(path_), EFI_FILE_MODE_READ | EFI_FILE_MODE_WRITE, EFI_FILE_HIDDEN | EFI_FILE_SYSTEM)))
			break;
	}

	if (file == nullptr)
		return;

	if(EFI_ERROR(file->Write(file, &size, data))){
		Print((CHAR16*)L"Failed to write\n");
	}
	
	root->Close(file);
	root->Close(root);

}

