#ifndef CPUREADER_H
#define CPUREADER_H

struct CpuData {
	unsigned long long total;
	unsigned long long idle;
};

class CpuReader {
    public:
	virtual CpuData readCpuData() = 0;
	virtual ~CpuReader() = default;
};

#endif  // CPUREADER_H