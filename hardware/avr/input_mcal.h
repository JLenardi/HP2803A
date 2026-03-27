/**
 * @file input_mcal.h
 * @brief
 */

#ifndef INPUT_MCAL_H
#define INPUT_MCAL_H

#include <stdbool.h>
#include "hw_input.h"
#include "input_volatile.h"
#include "timer_mcal.h"

void input_mcal_init(void);
void input_mcal_enable(void);
HWKey input_mcal_poll_key(void);
void cycle_button_input_line(void);

#endif

