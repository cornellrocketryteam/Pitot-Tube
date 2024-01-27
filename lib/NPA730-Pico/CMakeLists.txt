add_library(NPA730-Pico INTERFACE)

target_sources(NPA730-Pico INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/npa730.cpp
)

target_link_libraries(NPA730-Pico INTERFACE
    hardware_i2c
    pico_stdlib
)