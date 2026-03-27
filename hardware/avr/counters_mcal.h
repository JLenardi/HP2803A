/**
 * @file counters_mcal.h
 * @brief
 */

#ifndef COUNTERS_MCAL_H
#define COUNTERS_MCAL_H

#include <stdbool.h>
#include <stdint.h>

bool counters_gate_closed(void);
void counters_read(uint32_t * counts);
void counters_restart(void);

#endif

