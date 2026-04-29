# CMakeLists.txt file for windows
add_library(platform
    windows_cpu_reader.cpp
    windows_memory_reader.cpp
)

target_include_directories(platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)