/**
 * @file gpio_mcal.h
 * @brief
 */

#ifndef GPIO_MCAL_H
#define GPIO_MCAL_H

#include <stdint.h>
#include "sys_settings_types.h"

void gpio_mcal_init(void);
void gpio_set_timebase(TimebaseOption timebase);
TimebaseOption gpio_get_timebase(void);

#endif

