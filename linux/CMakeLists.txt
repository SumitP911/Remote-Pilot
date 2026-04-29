# CMakeLists.txt file for linux
add_library(platform
    linux_cpu_reader.cpp
    linux_memory_reader.cpp
)

target_include_directories(platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
