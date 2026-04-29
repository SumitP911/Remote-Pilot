cmake_minimum_required(VERSION 3.15)
project(RemotePilotAgent)

set(CMAKE_CXX_STANDARD 17)

# Detect OS and include relevant platform-specific code
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
add_subdirectory(linux)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
add_subdirectory(windows)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
add_subdirectory(mac)
else()
message(FATAL_ERROR "Unsupported platform")
endif()

# Add common code
add_subdirectory(common)

# Main executable
add_executable(remote-pilot-agent main.cpp)

# Link against common + platform-specific code
target_link_libraries(remote-pilot-agent PRIVATE common platform)