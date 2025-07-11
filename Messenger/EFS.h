#pragma once

class CEmbeddingFS : public CObject
{
public:
	CEmbeddingFS() noexcept;

	bool Open(CString fileName);
	void Close();
	bool IsOpenned();

	void SetFlushPolicy(bool autoFlush) noexcept;
	bool GetFlushPolicy() noexcept;

	void Flush();

	bool ReadSimpleObject(CString path, void* obj, int objsz);
	CString ReadStringData(CString path, LPCSTR name);
	int ReadDynamicObject(CString path, LPCSTR name, void* obj, int maxsz);

	bool WriteSimpleObject(CString path, void* obj, int objsz);
	bool WriteStringData(CString path, LPCSTR name, CString val);
	bool WriteDynamicObject(CString path, LPCSTR name, void* obj, int maxsz);

    void CreateSimpleObject(CString path, LPCSTR name);
    void RemoveSimpleObject(CString path);
private:
	CFile dt;

	static const unsigned long long NONE = -1;

	struct file_header_small
	{
		char sign[4]; // ONE OF - CAB (always big header) FILE (small header) DATA (big header) MAP
		unsigned long long prev;
		unsigned long long size;
	};

	// FOR FILES BIGGER THAN 256 bytes
	struct file_header_big : file_header_small
	{
		unsigned char hash[32];
	};

	struct map_header
	{

	};
	
	void lol()
	{
		sizeof(file_header_big);
		sizeof(file_header_small);
		
	}

	struct type_header
	{
		
	};
};
/*

#include <iostream>
#include <windows.h>

#define BUF_SIZE 4096

int main() {
    const wchar_t* path = L"C:\\path\\to\\your\\directory"; // Specify the directory to watch
    HANDLE dir_handle = CreateFileW(
        path,
        FILE_LIST_DIRECTORY,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        nullptr,
        OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED,
        nullptr
    );

    if (dir_handle == INVALID_HANDLE_VALUE) {
        std::wcerr << L"Error opening directory: " << GetLastError() << std::endl;
        return 1;
    }

    char buffer[BUF_SIZE];
    DWORD bytes_returned;

    while (true) {
        BOOL success = ReadDirectoryChangesW(
            dir_handle,
            buffer,
            BUF_SIZE,
            TRUE, // Watch subdirectories as well
            FILE_NOTIFY_CHANGE_FILE_NAME |
            FILE_NOTIFY_CHANGE_DIR_NAME |
            FILE_NOTIFY_CHANGE_ATTRIBUTES |
            FILE_NOTIFY_CHANGE_SIZE |
            FILE_NOTIFY_CHANGE_LAST_WRITE |
            FILE_NOTIFY_CHANGE_SECURITY,
            &bytes_returned,
            nullptr,
            nullptr
        );

        if (!success) {
            std::wcerr << L"Error reading directory changes: " << GetLastError() << std::endl;
            break;
        }

        DWORD offset = 0;
        do {
            FILE_NOTIFY_INFORMATION* fni = (FILE_NOTIFY_INFORMATION*)(buffer + offset);

            std::wcout << L"Action: ";
            switch (fni->Action) {
            case FILE_ACTION_ADDED:
                std::wcout << L"Added";
                break;
            case FILE_ACTION_REMOVED:
                std::wcout << L"Removed";
                break;
            case FILE_ACTION_MODIFIED:
                stdClout << L"Modified";
                break;
            case FILE_ACTION_RENAMED_OLD_NAME:
                std::wcout << L"Renamed (Old Name)";
                break;
            case FILE_ACTION_RENAMED_NEW_NAME:
                std::wcout << L"Renamed (New Name)";
                break;
            default:
                std::wcout << L"Unknown";
                break;
            }
            std::wcout << L" File: " << std::wstring(fni->FileName, fni->FileNameLength / sizeof(wchar_t)) << std::endl;

            offset += fni->NextEntryOffset;

        } while (offset != 0);
    }

    CloseHandle(dir_handle);
    return 0;
}*/

typedef unsigned long long (*seek_prog)(long long);

struct seek_stream
{

};

struct input_stream
{

};

struct file_metadata
{

};