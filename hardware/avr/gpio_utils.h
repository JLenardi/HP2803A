/**
 * @file gpio_utils.h
 * @brief
 */

#ifndef GPIO_UTILS_H
#define GPIO_UTILS_H

typedef uint8_t GpioPort;
enum GpioPort_enum
{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD
};

void ddrc_set_outputs_protected(uint8_t mask);
void gpio_write_masked(uint8_t mask, uint8_t value, GpioPort port);
void toggle_START(void);
void toggle_WRITE(void);

#endif

