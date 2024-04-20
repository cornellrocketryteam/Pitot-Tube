#include "hardware/i2c.h"
#include "pico/stdlib.h"
#ifdef LAUNCH
#include "tusb.h"
#endif
#include "pins.hpp"
#include "pts.hpp"

PTS pts;

int main() {
    sleep_ms(2000000);
    stdio_init_all();

    i2c_init(i2c0, 400 * 1000);
    i2c_init(i2c1, 400 * 1000);

    gpio_set_function(I2C_SDA_0, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_0, GPIO_FUNC_I2C);

    gpio_set_function(I2C_SDA_1, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_1, GPIO_FUNC_I2C);

    gpio_pull_up(I2C_SDA_0);
    gpio_pull_up(I2C_SCL_0);

    gpio_pull_up(I2C_SDA_1);
    gpio_pull_up(I2C_SCL_1);

#ifndef LAUNCH
    while (!tud_cdc_connected()) {
        sleep_ms(500);
    }
    printf("Connected\n");
#endif

    while (true) {
        pts.execute();
    }
    return 0;
}