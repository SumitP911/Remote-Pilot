#ifndef LINUXCPUREADER_H
#define LINUXCPUREADER_H

#include "../common/interfaces/cpu_reader.h"

class LinuxCpuReader : public CpuReader {
    public:
	CpuData readCpuData() override;
};

#endif