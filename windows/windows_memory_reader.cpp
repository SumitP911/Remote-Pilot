#include "windows_memory_reader.h"

#include <windows.h>

#include <iostream>

WindowsMemoryReader::~WindowsMemoryReader() {}

MemoryData WindowsMemoryReader::readMemoryData() {
	MemoryData data = {0, 0};

	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(memInfo);

	if (GlobalMemoryStatusEx(&memInfo)) {
		data.total = static_cast<unsigned long long>(memInfo.ullTotalPhys);
		data.available =
		    static_cast<unsigned long long>(memInfo.ullAvailPhys);
	} else {
		std::cerr << "Failed to get memory status. Error: " << GetLastError()
		          << std::endl;
	}

	return data;
}