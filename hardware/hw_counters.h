/**
 * @file
 * @brief Hardware abstraction interface for counter acquisition.
 *
 * The functions declared in this interface are implemented separately for
 * a64 and avr builds, with matching platform-specific source files.
 */

#ifndef HW_COUNTERS_H
#define HW_COUNTERS_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Indicates whether counter values are ready to be read.
 *
 * @return true if counter acquisition is complete, false otherwise.
 */
bool hw_counters_ready(void);

/**
 * @brief Reads the latest counter values.
 *
 * @param count_out Output array for two counter values.
 */
void hw_read_counters(uint32_t count_out[2]);

/**
 * @brief Restarts counter acquisition.
 */
void hw_restart_counters(void);

#endif /* HW_COUNTERS_H */

