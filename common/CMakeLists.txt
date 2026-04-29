# Common source files
add_library(common
    agent_core.cpp
    cpu_collector.cpp
    memory_collector.cpp
)

# Include interface and utils folders
target_include_directories(common PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/interfaces
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)
