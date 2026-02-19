/**
 * @file input_volatile.h
 * @brief
 */

#ifndef INPUT_VOLATILE_H
#define INPUT_VOLATILE_H

#include <stdbool.h>
#include "gpio_defs.h"

extern volatile HWKey int0_key;
extern volatile HWKey isr_key;
extern volatile bool request_int0_enable;

#endif /* INPUT_VOLATILE_H */

