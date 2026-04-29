#ifndef WINDOWSMEMORYREADER_H
#define WINDOWSMEMORYREADER_H

#include "../common/interfaces/memory_reader.h"

class WindowsMemoryReader : public MemoryReader {
    public:
	MemoryData readMemoryData() override;
	~WindowsMemoryReader() override;
};

#endif