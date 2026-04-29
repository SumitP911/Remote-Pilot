#include "agent_core.h"

#include <chrono>
#include <iostream>
#include <thread>

#include "cpu_collector.h"
#include "memory_collector.h"

#if defined(_WIN32)
#include "../windows/windows_cpu_reader.h"
#include "../windows/windows_memory_reader.h"
#elif defined(__APPLE__)
#include "../mac/mac_cpu_reader.h"
#else
#include "../linux/linux_cpu_reader.h"
#include "../linux/linux_memory_reader.h"
#endif

AgentCore::AgentCore() {}

void AgentCore::run() {
	std::unique_ptr<CpuReader> cpuReader;
	std::unique_ptr<MemoryReader> memoryReader;
#if defined(_WIN32)
	cpuReader = std::make_unique<WindowsCpuReader>();
	memoryReader = std::make_unique<WindowsMemoryReader>();
#elif defined(__APPLE__)
	cpuReader = std::make_unique<MacCpuReader>();
#else
	cpuReader = std::make_unique<LinuxCpuReader>();
	memoryReader = std::make_unique<LinuxMemoryReader>();
#endif

	CpuCollector cpuCollector(std::move(cpuReader));
	MemoryCollector memoryCollector(std::move(memoryReader));

	std::cout << "Remote Pilot Agent\n";

	while (true) {
		cpuCollector.update();
		memoryCollector.update();

		std::cout << "CPU Usage: " << cpuCollector.getUsage() << "%\n";
		std::cout << "Memory Usage: " << memoryCollector.getUsage() << "%"
		          << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}