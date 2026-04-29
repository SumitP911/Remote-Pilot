#ifndef LINUXMEMORYREADER_H
#define LINUXMEMORYREADER_H

#include "../common/interfaces/memory_reader.h"

class LinuxMemoryReader : public MemoryReader {
    public:
	~LinuxMemoryReader() override;
	MemoryData readMemoryData() override;
};

#endif  // LINUXMEMORYREADER_H
