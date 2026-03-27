/**
 * @file hw_input.h
 * @brief
 */

#ifndef HW_INPUT_H
#define HW_INPUT_H

#include <stdint.h>

typedef uint8_t HWKey;
enum HWKey_enum
{
    HW_KEY_SELECT  = 4,
    HW_KEY_BACK,
    HW_KEY_CANCEL,
    HW_KEY_UNUSED,
    HW_KEY_ROTA    = 8,
    HW_KEY_ROTB,
    HW_KEY_INVALID,
    HW_KEY_NULL    = 0  // No interrupt activity
};

void hw_input_init(void);
HWKey hw_input_poll_key(void);

#endif

