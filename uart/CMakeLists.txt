cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set the project name
project(uart C CXX ASM)

# Set the C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17) 

# Creat a subdirectory for pico-sdk ibraries
pico_sdk_init()

# Add your executable to tell cmake where to find main.c file
add_executable(${PROJECT_NAME} main.c)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME} pico_stdlib)