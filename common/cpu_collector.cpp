#include "cpu_collector.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

CpuCollector::CpuCollector(std::unique_ptr<CpuReader> reader)
    : cpuReader(std::move(reader)), prevIdle(0), prevTotal(0), lastUsage(0.0) {}

// Function to collect CPU Metrics
void CpuCollector::update() {
	CpuData data = cpuReader->readCpuData();

	unsigned long long deltaIdle = data.idle - prevIdle;
	unsigned long long deltaTotal = data.total - prevTotal;

	if (deltaTotal != 0) {
		lastUsage = 100.0 * (1.0 - (double)deltaIdle / deltaTotal);
	}

	prevIdle = data.idle;
	prevTotal = data.total;
}

double CpuCollector::getUsage() const { return lastUsage; }