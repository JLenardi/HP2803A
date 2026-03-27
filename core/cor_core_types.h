/**
 * @file cor_core_types.h
 * @brief Defines type aliases and data structures for system settings.
 */

#ifndef COR_CORE_TYPES_H
#define COR_CORE_TYPES_H

#include <stdint.h>

typedef uint8_t MenuCategory;
enum MenuCategory_enum
{
    CAT_NONE,
    CAT_DISPLAY1,
    CAT_DISPLAY2,
    CAT_UNITS,
    CAT_RESOLUTION,
    CAT_BRIGHTNESS,
    CAT_TIMEBASE,
    CAT_SOCKETS,
    CAT_PROBE_A,
    CAT_PROBE_B,
    CAT_TRANSMIT,
    CAT_SETTINGS,
    CAT_PROBE_DB,
    CAT_PROBE_CORE,
    CAT_PROBE_CF
};

typedef uint8_t BrightnessOption;
enum BrightnessOption_enum
{
    BRT_SHOW,
    BRT_MAIN,
    BRT_OTHER
};

typedef uint8_t SettingsOption;
enum SettingsOption_enum
{
    SETTINGS_SAVE,
    SETTINGS_DISCARD,
    SETTINGS_DEFAULT
};

typedef uint8_t EditProbeCoreOption;
enum EditProbeCoreOption_enum
{
    PROBE_CORE_IDX,
    PROBE_CORE_PARAM,
    PROBE_CORE_VALUE,
};

typedef uint8_t EditProbeCFOption;
enum EditProbeCFOption_enum
{
    PROBE_CF_IDX,
    PROBE_CF_PARAM,
    PROBE_CF_VALUE,
};

typedef uint8_t MenuFlow;
enum MenuFlow_enum
{
    MENU_FLOW_SELECT,
    MENU_FLOW_HOLD,
    MENU_FLOW_BACK,
    MENU_FLOW_CANCEL
};

typedef struct
{
    MenuCategory menu_category;
    uint8_t      selected_value;
} ActionContext;

#endif

