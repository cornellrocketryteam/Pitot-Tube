cmake_minimum_required(VERSION 3.27)

# Pull in SDK (must be before project)
include(lib/pico-sdk/pico_sdk_init.cmake)

project(pts C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add compiler flags and definitions
add_compile_options(
    -Wall
    -Wno-format          
    -Wno-unused-function
)

# add_definitions(-DVERBOSE)
add_definitions(-DLAUNCH)

# Add source files from src/
set(SOURCES
    src/main.cpp
    src/pts.cpp
    src/hw_config.c
)

# Add all executables
add_executable(${PROJECT_NAME}
    ${SOURCES}
)

# Add external libraries
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/no-OS-FatFS-SD-SDIO-SPI-RPi-Pico/src build)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/NPA730-Pico)

# Link library directories
target_link_directories(${PROJECT_NAME} 
    PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/NPA730-Pico
)

# Include library headers
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/NPA730-Pico
)

# Pull in common dependencies
target_link_libraries(${PROJECT_NAME} 
    pico_stdlib
    hardware_i2c
    no-OS-FatFS-SD-SDIO-SPI-RPi-Pico
    NPA730-Pico
)

# Enable serial over USB
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})