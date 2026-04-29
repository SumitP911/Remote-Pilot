#include "linux_memory_reader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

LinuxMemoryReader::~LinuxMemoryReader() {};

MemoryData LinuxMemoryReader::readMemoryData() {
	MemoryData data = {0, 0};

	std::ifstream file("/proc/meminfo");
	if (!file.is_open()) {
		std::cerr << "Error: Could not open /proc/meminfo" << std::endl;
		return data;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string key;
		unsigned long long value;
		std::string unit;

		ss >> key >> value >> unit;

		if (key == "MemTotal:") {
			data.total = value;
		} else if (key == "MemAvailable:") {
			data.available = value;
		}

		if (data.total && data.available) break;
	}

	return data;
}
