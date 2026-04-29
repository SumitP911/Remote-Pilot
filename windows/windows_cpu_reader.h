#ifndef WINDOWSCPUREADER_H
#define WINDOWSCPUREADER_H

#include "../common/interfaces/cpu_reader.h"

class WindowsCpuReader : public CpuReader {
    public:
	CpuData readCpuData() override;
};

#endif