#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "../common/time.h"

/*
 * Periodic task with low priority and 33 Hertz frequency.
 *
 * Note : Higher priorities cause error on runtime. Remain low priority.
*/

extern int FUZE_STATUS;

#define AUX5_TIMER_LIMIT_MS 5000
#define AUX5_FAILSAFE_VALUE 2500

extern uint32_t AUX5_FAILSAFE_TIMER;

extern bool AUX5_FAILSAFE_TIMER_ON;

void taskDonmezoglu(timeUs_t currentTimeUs);

void donmezogluSerialPrintS(const char* str);

void donmezogluSerialPrintC(uint8_t ch);