#include "linux_cpu_reader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

CpuData LinuxCpuReader::readCpuData() {
	CpuData data = {0, 0};

	std::ifstream inFile("/proc/stat");
	if (!inFile.is_open()) {
		std::cerr << "Error: Could not open /proc/stat" << std::endl;
		return data;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		if (line.rfind("cpu ", 0) == 0) {
			std::istringstream ss(line);
			std::string cpuLabel;
			unsigned long long user, nice, system, idle, iowait, irq,
			    softirq, steal;
			ss >> cpuLabel >> user >> nice >> system >> idle >> iowait >>
			    irq >> softirq >> steal;

			data.total =
			    user + nice + system + idle + iowait + irq + softirq + steal;
			data.idle = idle + iowait;
			break;
		}
	}

	return data;
}
