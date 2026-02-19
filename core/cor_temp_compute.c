/**
 * @file cor_temp_compute.c
 * @brief
 */

#include <stdint.h>
#include "sys_settings.h"
#include "cor_core_defs.h"
#include "cor_probe_db.h"
#include "cor_temp_compute.h"
#include "sys_settings_types.h"

void calc_celsius_from_count(const uint32_t * counts_in, float * temps_out)
{
    int probe_idx[2];

    const Settings * curr_settings = get_current_settings();

    probe_idx[0] = curr_settings->probe_a_option;
    probe_idx[1] = curr_settings->probe_b_option;

    for (int i = 0; i < 2; ++i)
    {
        const float count = (float)counts_in[i];
        float temp = 0.0;

        const CalibrationEntry * core_entry = probe_db_get_core_entry(probe_idx[i]);
        const float slope = (float)(core_entry->slope);
        const float cfz   = (float)(core_entry->cfz);

        if (count >= COUNT_MIN_10SEC && count <= COUNT_MAX_10SEC)
        {
            temp =   1.0f * (count - 282080000.0f) / slope + cfz / 1000.0f;
        }
        else if (count >= COUNT_MIN_1SEC && count <= COUNT_MAX_1SEC)
        {
            temp =  10.0f * (count -  28208000.0f) / slope + cfz / 1000.0f;
        }
        else if (count >= COUNT_MIN_100MS && count <= COUNT_MAX_100MS)
        {
            temp = 100.0f * (count -   2820800.0f) / slope + cfz / 1000.0f;
        }

        temps_out[i] = temp;
    }
}

