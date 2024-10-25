#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class Memory {
private:
	DWORD id = 0; // ID of process
	HANDLE process = NULL; // Handle to process
public:
	Memory(const char* processName);
	~Memory();

	DWORD GetProcessId();
	HANDLE GetProcessHandle();

	uintptr_t GetModuleAddress(const char* moduleName);

	template <typename T>
	T ReadMemory(uintptr_t address) {
		T value;
		ReadProcessMemory(this->process, (LPCVOID)address, &value, sizeof(T), NULL);
		return value;
	}

	template <typename T>
	bool WriteMemory(uintptr_t address, T value) {
		return WriteProcessMemory(this->process, (LPVOID)address, &value, sizeof(T), NULL);
	}

	uintptr_t GetPointerAddress(uintptr_t gameBaseAddr, uintptr_t address, std::vector<unsigned int> offsets);
};