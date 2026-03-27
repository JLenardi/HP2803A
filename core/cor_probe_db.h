/**
 * @file cor_probe_db.h
 * @brief
 */
#ifndef COR_PROBE_DB_H
#define COR_PROBE_DB_H

#include <stdint.h>

#define NUM_PROBES       5
#define CF_TEMP_MIN    -80
#define CF_TEMP_MAX    250
#define CF_TEMP_STEP    10
#define NUM_PARAMS_CORE  3
#define NUM_PARAMS_CF (((CF_TEMP_MAX - CF_TEMP_MIN) / CF_TEMP_STEP) + 1)

typedef struct
{
    uint16_t serial_num;
    uint16_t slope;
    int16_t  cfz;
} CalibrationEntry;

typedef struct
{
    int8_t cf[NUM_PARAMS_CF];
} CorrectionFactorEntry;

void probe_db_init(void);
void probe_db_save_current_core(void);
void probe_db_discard_current_core(void);
void probe_db_use_default_core(void);
void probe_db_save_current_cf(void);
void probe_db_discard_current_cf(void);
void probe_db_use_default_cf(void);

const CalibrationEntry * probe_db_get_core_entry(int probe_index);
CalibrationEntry * probe_db_get_core_entry_mutable(int probe_index);
const CorrectionFactorEntry * probe_db_get_cf_entry(int probe_index);
CorrectionFactorEntry * probe_db_get_cf_entry_mutable(int probe_index);

#endif

