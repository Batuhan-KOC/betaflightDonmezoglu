#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "../common/time.h"

/*
 * Periodic task with low priority and 33 Hertz frequency.
 *
 * Note : Higher priorities cause error on runtime. Remain low priority.
*/
void taskDonmezoglu(timeUs_t currentTimeUs);

void donmezogluSerialPrintS(const char* str);

void donmezogluSerialPrintC(uint8_t ch);