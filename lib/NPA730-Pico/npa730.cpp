#include "npa730.hpp"
#include <cstdio>

NPA730::NPA730(i2c_inst_t *i2c_type) {
    i2c = i2c_type;
}

bool NPA730::read(int *pressure, int *temp) {
    uint8_t buf[4];

    i2c_read_blocking(i2c, NPA730_ADDR, buf, 4, false);

    uint16_t pressure_reading = ((buf[0] & 0b00111111) << 8) | buf[1];
    uint16_t temp_reading = (buf[2] << 3) | (buf[3] >> 5);

    *pressure = pressure_reading;
    *temp = temp_reading;

    return true;
}