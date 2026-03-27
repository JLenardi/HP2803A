/**
 * @file sys_counters.h
 * @brief Service layer interface for reading and controlling counters.
 */

#ifndef SYS_COUNTERS_H
#define SYS_COUNTERS_H

#include <stdbool.h>
#include <stdint.h>

bool sample_period_complete(void);
void sys_restart_counters(void);
void read_measurement(void);
const uint32_t * get_counts(void);

#endif

