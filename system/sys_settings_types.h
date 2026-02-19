/**
 * @file sys_settings_types.h
 * @brief Defines type aliases and data structures for system settings.
 */

#ifndef SYS_SETTINGS_TYPES_H
#define SYS_SETTINGS_TYPES_H

#include <stdint.h>

typedef uint8_t DisplayOption;
enum DisplayOptions_enum
{
    DISPLAY_T_MIN = 1,              // "enum with symbolic bounds"
    DISPLAY_T1 = DISPLAY_T_MIN,     // lower bound of temperature options
    DISPLAY_T2,
    DISPLAY_T1MINUST2,
    DISPLAY_T2MINUST1,
    DISPLAY_DELTAT1,
    DISPLAY_DELTAT2,
    DISPLAY_MINT1,
    DISPLAY_MINT2,
    DISPLAY_MAXT1,
    DISPLAY_MAXT2,
    DISPLAY_T_MAX = DISPLAY_MAXT2,  // upper bound of temperature options
    DISPLAY_COUNT1,
    DISPLAY_COUNT2
};

typedef uint8_t UnitsOption;
enum UnitsOption_enum
{
    UNITS_CELSIUS,
    UNITS_FAHRENHEIT,
    UNITS_KELVIN
};

typedef uint8_t ResolutionOption;
enum ResolutionOption_enum
{
    RES_SCALE1 = 1,
    RES_SCALE2,
    RES_SCALE3,
    RES_SCALE4
};

typedef uint8_t BrightnessValue;

typedef uint8_t TimebaseOption;
enum TimebaseOption_enum
{
    TIMEBASE_100MS,
    TIMEBASE_1SEC,
    TIMEBASE_10SEC,
    TIMEBASE_NA
};

typedef uint8_t SocketsOption;
enum SocketsOption_enum
{
    SOCKETS_FRONT,
    SOCKETS_BACK
};

typedef uint8_t ProbeOption;
enum ProbeOption_enum
{
    PROBE_IDX0,
    PROBE_IDX1,
    PROBE_IDX2
};

typedef uint8_t TransmitOption;
enum TransmitOption_enum
{
    TRANSMIT_ON,
    TRANSMIT_OFF
};

typedef struct
{
    DisplayOption    display1_option;
    DisplayOption    display2_option;
    UnitsOption      units_option;
    ResolutionOption resolution_option;
    TimebaseOption   timebase_option;
    BrightnessValue  brightness_value;
    SocketsOption    sockets_option;
    ProbeOption      probe_a_option;
    ProbeOption      probe_b_option;
    TransmitOption   transmit_option;
} Settings;

#endif // SYS_SETTINGS_TYPES_H

