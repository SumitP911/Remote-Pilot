#ifndef CPUCOLLECTOR_H
#define CPUCOLLECTOR_H

#include <memory>

#include "interfaces/cpu_reader.h"

class CpuCollector {
    public:
	CpuCollector(std::unique_ptr<CpuReader> reader);
	void update();
	double getUsage() const;

    private:
	std::unique_ptr<CpuReader> cpuReader;
	unsigned long long prevIdle = 0;
	unsigned long long prevTotal = 0;
	double lastUsage = 0.0;
};

#endif  // CPUCOLLECTOR_H
