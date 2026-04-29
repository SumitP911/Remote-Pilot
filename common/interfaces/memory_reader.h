#ifndef MEMORYREADER_H
#define MEMORYREADER_H

struct MemoryData {
	unsigned long long total;
	unsigned long long available;
};

class MemoryReader {
    public:
	virtual MemoryData readMemoryData() = 0;
	virtual ~MemoryReader() = default;
};

#endif  // MEMORYREADER_H
