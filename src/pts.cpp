#include "pts.hpp"
#include "npa730.hpp"
#include "pins.hpp"
#include <cstdio>

NPA730 npa730_1(I2C_PORT);

PTS::PTS() {
    npa730_1.begin();

    pSD = sd_get_by_num(0);
    FRESULT fr = f_mount(&fs, "", 1);

    if (fr != FR_OK) {
#ifdef VERBOSE
        printf("SD: %s (%d)\n", FRESULT_str(fr), fr);
#endif
    }
}

void PTS::execute() {
    npa730_1.read(&pressure_1, &temperature_1);

    FRESULT fr = f_open(&file, "log.txt", FA_OPEN_APPEND | FA_WRITE);

    if (fr != FR_OK && fr != FR_EXIST) {
#ifdef VERBOSE
        printf("SD: %s (%d)\n", FRESULT_str(fr), fr);
#endif
    }

    if (f_printf(&file, "%d,%d,%d\n", to_ms_since_boot(get_absolute_time()), pressure_1, temperature_1) < 0) {
#ifdef VERBOSE
        printf("SD: %s (%d)\n", FRESULT_str(fr), fr);
#endif
    }

    fr = f_close(&file);
    if (FR_OK != fr) {
#ifdef VERBOSE
        printf("SD: %s (%d)\n", FRESULT_str(fr), fr);
#endif
    }
}