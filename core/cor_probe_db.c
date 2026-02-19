/**
 * @file cor_probe_db.c
 * @brief
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "cor_probe_db.h"

const CalibrationEntry default_entry_core[NUM_PROBES] =
{
    {11623,  9855, -134},
    {11642,  9855, -139},
    {11601, 10000,    0},
    {11602, 10000,    0},
    {11603, 10000,    0}
};

const CorrectionFactorEntry default_entry_cf[NUM_PROBES] =
{
    {{-64, -45, -31, -20, -12, -7, -3, -1, 0, 0, 0, -1, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2, 3, 4, 4, 4, 4, 4, 3, 1, -1, -4, -8, -12}},
    {{-60, -42, -28, -18, -11, -6, -2, -1, 0, 0, 0, -1, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2, 3, 3, 4, 4, 4, 3, 2, 1, -2, -4, -7, -11}},
    {{0}},
    {{0}},
    {{0}}
};

CalibrationEntry current_entry_core[NUM_PROBES];
CalibrationEntry saved_entry_core[NUM_PROBES];

CorrectionFactorEntry current_entry_cf[NUM_PROBES];
CorrectionFactorEntry saved_entry_cf[NUM_PROBES];

void probe_db_init(void)
{
    probe_db_use_default_core();
    probe_db_use_default_cf();
}

void probe_db_save_current_core(void)
{
    memcpy(saved_entry_core, current_entry_core, sizeof(saved_entry_core));
}

void probe_db_discard_current_core(void)
{
    memcpy(current_entry_core, saved_entry_core, sizeof(current_entry_core));
}

void probe_db_use_default_core(void)
{
    memcpy(current_entry_core, default_entry_core, sizeof(current_entry_core));
    memcpy(saved_entry_core,   default_entry_core, sizeof(saved_entry_core));
}

void probe_db_save_current_cf(void)
{
    memcpy(saved_entry_cf, current_entry_cf, sizeof(saved_entry_cf));
}

void probe_db_discard_current_cf(void)
{
    memcpy(current_entry_cf, saved_entry_cf, sizeof(current_entry_cf));
}

void probe_db_use_default_cf(void)
{
    memcpy(current_entry_cf, default_entry_cf, sizeof(current_entry_cf));
    memcpy(saved_entry_cf,   default_entry_cf, sizeof(saved_entry_cf));
}

const CalibrationEntry * probe_db_get_core_entry(int probe_index)
{
    if (probe_index >= NUM_PROBES)
    {
        return NULL;
    }
    return &current_entry_core[probe_index];
}

CalibrationEntry * probe_db_get_core_entry_mutable(int probe_index)
{
    if (probe_index >= NUM_PROBES)
    {
        return NULL;
    }
    return &current_entry_core[probe_index];
}

const CorrectionFactorEntry * probe_db_get_cf_entry(int probe_index)
{
    if (probe_index >= NUM_PROBES)
    {
        return NULL;
    }
    return &current_entry_cf[probe_index];
}

CorrectionFactorEntry * probe_db_get_cf_entry_mutable(int probe_index)
{
    if (probe_index >= NUM_PROBES)
    {
        return NULL;
    }
    return &current_entry_cf[probe_index];
}

