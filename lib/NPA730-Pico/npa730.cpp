#include "npa730.hpp"
#include <cstdio>

NPA730::NPA730(i2c_inst_t* i2c_type) {
    i2c = i2c_type;
}

bool NPA730::begin() {
    // TODO: Change I2C address

    return true;
}

bool NPA730::read(double *pressure, double *temp) {
    uint8_t buf[4];

    double pressure_min = -1.25;
    double pressure_max = 11.25;

    i2c_read_blocking(i2c, NPA730_ADDR, buf, 4, false);

    uint16_t pressure_reading = ((buf[0] & 0b00111111) << 8) | buf[1];

    uint16_t temp_reading = (buf[2] << 3) | (buf[3] >> 5);

    //printf("pressure: %d\n", (pressure_reading * (pressure_max - pressure_min) / 16383 + pressure_min));
    printf("pressure: %d\n", pressure_reading);
    printf("temp: %d\n", temp_reading);
    // for (int i = 0; i < 4; i++) {
    //     printf("%d: %d\n", i, buf[i]);
    // }

    return true;
}