#include "memory.h"
#include <TlHelp32.h>
#include <vector>

Memory::Memory(const char *processName)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	while (Process32Next(snapshot, &entry))
	{
		if (!strcmp(entry.szExeFile, processName))
		{
			this->id = entry.th32ProcessID;
			this->process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->id);
			break;
		}
	}

	if (snapshot)
		CloseHandle(snapshot);
}

Memory::~Memory()
{
	if (this->process)
		CloseHandle(this->process);
}

DWORD Memory::GetProcessId()
{
	return this->id;
}

HANDLE Memory::GetProcessHandle()
{
	return this->process;
}

uintptr_t Memory::GetModuleAddress(const char *moduleName)
{
	MODULEENTRY32 entry;
	entry.dwSize = sizeof(MODULEENTRY32);

	const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, this->id);

	uintptr_t result = 0;

	while (Module32Next(snapshot, &entry))
	{
		if (!strcmp(entry.szModule, moduleName))
		{
			result = reinterpret_cast<uintptr_t>(entry.modBaseAddr);
			break;
		}
	}

	if (snapshot)
		CloseHandle(snapshot);

	return result;
}

uintptr_t Memory::GetPointerAddress(uintptr_t gameBaseAddr, uintptr_t address, std::vector<unsigned int> offsets)
{
	;
	DWORD offset_null = NULL;
	ReadProcessMemory(this->process, (LPVOID *)(gameBaseAddr + address), &offset_null, sizeof(offset_null), 0);
	DWORD pointeraddress = offset_null;			 // the address we need
	for (int i = 0; i < offsets.size() - 1; i++) // we dont want to change the last offset value so we do -1
	{
		ReadProcessMemory(this->process, (LPVOID *)(pointeraddress + offsets.at(i)), &pointeraddress, sizeof(pointeraddress), 0);
	}
	return pointeraddress += offsets.at(offsets.size() - 1); // adding the last offset
}