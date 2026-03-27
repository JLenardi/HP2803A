/**
 * @file cor_data_provider.h
 * @brief
 */

#ifndef COR_DATA_PROVIDER_H
#define COR_DATA_PROVIDER_H

#include <stdint.h>
#include "sys_settings_types.h"

const float * cor_get_temps(void);
const uint32_t * cor_get_counts(void);
const Settings * cor_get_current_settings(void);
char * cor_get_output_buf_mutable(void);

#endif

