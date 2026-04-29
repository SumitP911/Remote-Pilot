#include "memory_collector.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

MemoryCollector::MemoryCollector(std::unique_ptr<MemoryReader> reader)
    : memoryReader(std::move(reader)) {}

// Function to collect memory metrics
void MemoryCollector::update() {
	MemoryData data = memoryReader->readMemoryData();

	if (data.total != 0) {
		lastUsage =
		    100.0 * (1.0 - static_cast<double>(data.available) / data.total);
	}
}

double MemoryCollector::getUsage() const { return lastUsage; }