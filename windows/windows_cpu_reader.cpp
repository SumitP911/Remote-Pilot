#include "windows_cpu_reader.h"

#include <windows.h>

#include <iostream>

CpuData WindowsCpuReader::readCpuData() {
	CpuData data = {0, 0};

	FILETIME idleTime, kernelTime, userTime;

	if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
		// Convert FILETIME to Unsigned Long Long
		auto fileTimeToULL = [](const FILETIME& ft) -> unsigned long long {
			return (static_cast<unsigned long long>(ft.dwHighDateTime)
			        << 32) |
			       ft.dwLowDateTime;
		};

		unsigned long long idle = fileTimeToULL(idleTime);
		unsigned long long kernel = fileTimeToULL(kernelTime);
		unsigned long long user = fileTimeToULL(userTime);

		data.idle = idle;
		data.total = kernel + user;
	} else {
		std::cerr << "Failed to get system times" << std::endl;
	}

	return data;
}
