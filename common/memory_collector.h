#ifndef MEMORYCOLLECTOR_H
#define MEMORYCOLLECTOR_H

#include <memory>

#include "interfaces/memory_reader.h"

class MemoryCollector {
    public:
	MemoryCollector(std::unique_ptr<MemoryReader> reader);
	void update();
	double getUsage() const;

    private:
	std::unique_ptr<MemoryReader> memoryReader;
	double lastUsage = 0.0;
};

#endif  // MEMORYCOLLECTOR_H