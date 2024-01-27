#ifndef NPA730_HPP
#define NPA730_HPP

#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define NPA730_ADDR (0x28)

class NPA730 {
public:
    NPA730(i2c_inst_t *i2c_type);
    bool begin();
    bool read(double *pressure, double *temp);

private:
    i2c_inst_t *i2c;
};

#endif