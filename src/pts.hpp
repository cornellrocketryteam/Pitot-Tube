#ifndef PTS_HPP
#define PTS_HPP

#include "f_util.h"
#include "ff.h"
#include "hw_config.h"

class PTS {
public:
    PTS();
    void execute();

private:
    double pressure, temperature;
    FATFS fs;
    sd_card_t *pSD;
    FIL file;
};

#endif