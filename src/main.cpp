#include "pico/stdlib.h"
#include "hardware/i2c.h"
#ifdef DEBUG
#include "tusb.h"
#endif
#include "pts.hpp"
#include "pins.hpp"

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