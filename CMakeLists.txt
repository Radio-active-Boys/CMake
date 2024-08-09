cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(Code)

# Include directories for headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Find all .cpp files in the include/lib directory and set them as source files
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_compile_definitions(DEBUG)
endif()

if(CMAKE_BUILD_TYPE MATCHES "Release")
    add_compile_definitions(RELEASE)
endif()
# Add the executable and link all source files
add_executable(${PROJECT_NAME} ${SOURCES})
