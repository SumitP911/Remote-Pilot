<div align="center">

# 🖥️ Remote Pilot — Agent

[![C++](https://img.shields.io/badge/C++-17-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org)
[![CMake](https://img.shields.io/badge/CMake-3.15+-064F8C?style=flat-square&logo=cmake&logoColor=white)](https://cmake.org)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey?style=flat-square)]()
[![Status](https://img.shields.io/badge/Status-In%20Development-orange?style=flat-square)]()

</div>

---

## 📋 Overview

The **Agent** is the core C++ component of the Remote Pilot project — a lightweight daemon that runs on the target server and collects system metrics, manages services, and executes commands on behalf of the central dashboard.

It is designed to be cross-platform, with platform-specific implementations for Linux, macOS, and Windows, sharing a common interface layer.

---

## 📂 Repository Structure

```
Agent/
├── common/                 # Shared interfaces and platform-agnostic code
├── linux/                  # Linux-specific implementation
├── mac/                    # macOS-specific implementation
├── windows/                # Windows-specific implementation
├── build/                  # Compiled output (generated)
├── cmake-build-debug/      # CMake debug build directory (generated)
├── CMakeLists.txt          # CMake build configuration
├── main.cpp                # Entry point
└── README.md               # ← You are here
```

---

## ⚙️ Build Requirements

| Tool | Version |
|------|---------|
| C++ Compiler | GCC / Clang / MSVC (C++17 support required) |
| CMake | 3.15 or higher |
| OS | Linux, macOS, or Windows |

---

## 🔧 Building the Agent

**1. Clone the repository and navigate to the Agent folder:**
```bash
git clone https://github.com/<your-username>/remote-pilot.git
cd remote-pilot/Agent
```

**2. Configure with CMake:**
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

For a debug build:
```bash
cmake -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
```

**3. Build:**
```bash
cmake --build build
```

The compiled binary will be available in the `build/` directory.

---

## 🏗️ Architecture

The agent uses a **platform-abstraction pattern** — shared logic lives in `common/`, while platform-specific system calls are implemented separately under `linux/`, `mac/`, and `windows/`. The `main.cpp` entry point bootstraps the appropriate implementation at runtime.

```
main.cpp
   │
   └─── common/agent_core.h   ← shared interface
            │
            ├─── linux/       ← Linux syscalls (procfs, systemd, etc.)
            ├─── mac/         ← macOS APIs (sysctl, launchctl, etc.)
            └─── windows/     ← Windows APIs (WMI, SCM, etc.)
```

---

## 🌐 Role in the Larger System

The Agent is one component of the **Remote Pilot** project:

```
[ Agent (C++) ]  ──WebSocket/REST──►  [ Spring Boot Backend ]
                                               │
                                               ▼
                                      [ React.js Dashboard ]
```

- The Agent runs on the **managed server**, collecting metrics and executing commands
- The **Spring Boot backend** communicates with the Agent and serves the frontend
- The **React.js dashboard** provides the administrator UI

---

## 📦 Planned Capabilities

- [ ] Real-time CPU, memory, disk, and network metric collection
- [ ] Service start / stop / restart control
- [ ] Custom command execution
- [ ] Log file access and streaming
- [ ] Secure communication with the backend (HTTPS / SSH)
- [ ] Cross-platform support (Linux, macOS, Windows)

---

## 📚 References

- [CMake Documentation](https://cmake.org/documentation/)
- [C++ Reference](https://en.cppreference.com)

---

<div align="center">

Part of the **Remote Pilot** — Remote Server Control and Monitoring Dashboard

</div>
