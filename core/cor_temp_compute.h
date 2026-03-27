/**
 * @file cor_temp_compute.h
 * @brief
 */

#ifndef COR_TEMP_COMPUTE_H
#define COR_TEMP_COMPUTE_H

#include <stdint.h>

void calc_celsius_from_count(const uint32_t * counts_in, float * temps_out);

#endif

