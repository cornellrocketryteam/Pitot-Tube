#ifndef PTS_HPP
#define PTS_HPP

#include "f_util.h"
#include "ff.h"
#include "hw_config.h"

class PTS {
public:
    /**
     * Sets up both pressure sensors and SD card interface.
     */
    PTS();

    /**
     * Reads from both pressure sensors and writes the data + timestamp to the SD card.
     */
    void execute();

private:
    /**
     * Raw pressure and temperature readings from both sensors.
     */
    int pressure_0, temperature_0;
    int pressure_1, temperature_1;

    /**
     * SD card interface metadata.
     */
    FATFS fs;
    sd_card_t *pSD;
    FIL file;

    /**
     * Counters for log file splitting and naming.
     */
    uint32_t cycle_count;
    int file_count;
};

#endif