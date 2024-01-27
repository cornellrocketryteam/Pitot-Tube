#include "hardware/i2c.h"
#include "pico/stdlib.h"
#ifdef DEBUG
#include "tusb.h"
#endif
#include "pins.hpp"
#include "pts.hpp"

PTS pts;

int main() {
    stdio_init_all();

    i2c_init(I2C_PORT, 400 * 1000);

    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);

    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

#ifdef DEBUG
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