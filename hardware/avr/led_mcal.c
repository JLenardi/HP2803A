/**
 * @file
 * @brief
 */

#include <stddef.h>      // For NULL
#include <stdint.h>
#include <string.h>      // For memcpy()
#include <avr/io.h>
#include <util/delay.h>
#include "hw_display.h"
#include "gpio_defs.h"
#include "gpio_utils.h"
#include "led_mcal.h"
#include "error.h"

void led_bus_write(uint8_t LedA, uint8_t LedD)
{
    uint8_t mask;
    uint8_t value;

    if ((PINB & (1 << PB4_nFL)) == 0)  // FLASH should be low (!FLASH high)
    {
        mask  = (1 << PB4_nFL);
        value = (1 << PB4_nFL);
        gpio_write_masked(mask, value, GPIO_PORTB);
    }

    /* Write to LedA using PORTA */
    mask  = 0xFF;
    value = LedA;
    gpio_write_masked(mask, value, GPIO_PORTA);

    /* Set PORTC to output */
    mask = 0xFF;
    ddrc_set_outputs_protected(mask);

    /* Write to LedD using PORTC */
    mask  = 0xFF;
    value = LedD;
    gpio_write_masked(mask, value, GPIO_PORTC);

    toggle_WRITE();   // Toggle PB0_nWR

    /* Reset */
    DDRC = 0x00;      // Return PORTC to input for safety reading counters
}

void led_write_flash(uint8_t LedA, uint8_t LedD)
{
    if (DDRC != 0x00)
    {
        error_fatal();    // PORTC should be input
    }
    if ((PINB & (1 << PB4_nFL)) == 0 )
    {
        error_fatal();    // FLASH should be low (!FLASH high)
    }

    uint8_t mask;
    uint8_t value;

    /* Ensure PA7 low */
    if ((PINA & (1 << PA7_ENABLE)) != 0)
    {
        mask  = (1 << PA7_ENABLE);
        value = (1 << PA7_ENABLE);
        gpio_write_masked(mask, value, GPIO_PORTA);
    }

    /* Set FLASH high (!FLASH low) */
    mask  = (1 << PB4_nFL);
    value = (0 << PB4_nFL);
    gpio_write_masked(mask, value, GPIO_PORTB);

    /* Write address to LedA using PORTA */
    mask  = 0xFF;
    value = LedA;
    gpio_write_masked(mask, value, GPIO_PORTA);

    /* Set PORTC PC0 to output */
    mask = 0x01;
    ddrc_set_outputs_protected(mask);

    /* Write to LedD using PORTC */
    mask  = 0x01;
    value = LedD;
    gpio_write_masked(mask, value, GPIO_PORTC);

    toggle_WRITE();                              // Toggle PB0_nWR

    /* Reset */
    DDRC = 0x00;                                 // Set PORTC to input
    mask  = (1 << PB4_nFL);
    value = (1 << PB4_nFL);
    gpio_write_masked(mask, value, GPIO_PORTB);  // Set FLASH low (!FLASH high)
}

void led_set_brightness(int display, uint8_t brightness)
{
    uint8_t LedA = 0;
    uint8_t LedD = 0;

    display    &= 0x03;
    brightness &= 0x07;

    LedA |= (uint8_t)(0x02 << PA3);        // Control word register
    LedA |= (uint8_t)(display << PA5);

    LedD |= (uint8_t)(1 << PC3);           // Flash disable
    LedD |= (uint8_t)(brightness << PC0);  // Brightness

    led_bus_write(LedA, LedD);

    _delay_us(1);
}

void led_set_blink(int display, uint8_t brightness, uint8_t blink)
{
    uint8_t LedA = 0;
    uint8_t LedD = 0;

    display    &= 0x03;
    brightness &= 0x07;
    blink       = blink ? 1 : 0;

    LedA |= (uint8_t)(0x02 << PA3);      // Control word register
    LedA |= (uint8_t)(display << PA5);

    LedD |= (uint8_t)(brightness << PC0);
    LedD |= (uint8_t)(1 << PC3);         // Flash disable
    LedD |= (uint8_t)(blink << PC4);     // Blink enable/disable

    led_bus_write(LedA, LedD);

    _delay_us(1);
}

static void led_put_char(uint8_t row, uint8_t col, char chr)
{
    if ((PINB & (uint8_t)(1 << PB4_nFL)) == 0)  // FLASH should be low (!FLASH high)
    {
        uint8_t mask  = (1 << PB4_nFL);
        uint8_t value = (1 << PB4_nFL);
        gpio_write_masked(mask, value, GPIO_PORTB);
    }

    /* Range control */
    row &= 0x03;
    col &= 0x07;
    chr &= 0x7F;

    /* Address (PORTA / LedA) */
    uint8_t LedA = 0x00;
    LedA |= (uint8_t)(col << PA0);   // A2:0 position
    LedA |= (uint8_t)(0x03 << PA3);  // A4:3 Access character RAM (fixed 0b11)
    LedA |= (uint8_t)(row << PA5);   // A7:5 Display number (0b0xx / PA7=0)

    /* Data (PORTC / LedD) */
    uint8_t LedD = 0x00;
    LedD |= (uint8_t)(chr << PC0);   // 128 ASCII code (mask 0x7F -> PD7=0)

    led_bus_write(LedA, LedD);
}

static void led_clear_unit(uint8_t row)
{
    /* Range control */
    row &= 0x03;

    uint8_t LedA = 0;
    LedA |= (uint8_t)(0x02 << PA3);   // A4:3 Access control word register (fixed 0b10)
    LedA |= (uint8_t)(row << PA5);    // A7:5 Display number (0bxx / PA7=0)

    uint8_t LedD = 0;
    LedD |= (uint8_t)(0x06 << PC0);   // D2:0 Brightness 13% (0b110)
    LedD |= (uint8_t)(1 << PC7);      // D7   Clear flash and character RAMS

    led_bus_write(LedA, LedD);

    _delay_us(150);                   // min. 110 µs required
}

void led_clear(void)
{
    for (uint8_t d = 0; d < DISPLAY_ROWS; ++d)
    {
        led_clear_unit(d);
    }
}

static void led_blank_unit(uint8_t row)
{
    char txt[8];
    memcpy(txt, "        ", 8);
    led_update_row(row, txt);
}

void led_blank(void)
{
    for (uint8_t row = 0; row < DISPLAY_ROWS; ++row)
    {
        led_blank_unit(row);
    }
}

void led_init(void)
{
    led_clear();
    led_blank();
}

void led_update_char(uint8_t row, int col, char view_buf_char)
{
    /* TODO: (if required) */
    (void)row;
    (void)col;
    (void)view_buf_char;
}

void led_update_row(uint8_t row, const char * view_buf_row)
{
    if (row >= DISPLAY_ROWS || view_buf_row == NULL)
    {
        return;
    }

    /* Range control */
    row &= 0x03;

    for (uint8_t col = 0; col < DISPLAY_COLS; ++col)
    {
        char chr = view_buf_row[col];

        led_put_char(row, col, chr);
#if 1
        _delay_us(50);
#endif
    }
}

void led_update(const char view_buf_in[][DISPLAY_COLS])
{
    if (view_buf_in == NULL)
    {
        return;
    }

    for (uint8_t row = 0; row < DISPLAY_ROWS; ++row)
    {
        led_update_row(row, view_buf_in[row]);
    }
}

