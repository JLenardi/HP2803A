/**
 * @file cor_probe_edit.h
 * @brief
 */

#ifndef COR_PROBE_EDIT_H
#define COR_PROBE_EDIT_H

#include "cor_core_types.h"
#include "cor_menu_types.h"

typedef struct
{
    int probe_idx;
    int param_idx;
    int value;
} ProbeTableContext;

MenuFlow probe_set_core_idx(void);
MenuFlow probe_set_core_param(void);
MenuFlow probe_set_core_value(void);

MenuFlow probe_set_cf_idx(void);
MenuFlow probe_set_cf_param(void);
MenuFlow probe_set_cf_value(void);


#endif

