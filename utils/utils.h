/**
 * @file utils.h
 * @brief
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#define MAX_DIGITS 5

typedef int8_t Sign;
enum Sign_enum
{
    NEGATIVE = -1,
    POSITIVE =  1
};

typedef uint8_t Nibble;
enum Nibble_enum
{
    NIBBLE_LOW  = 0,
    NIBBLE_HIGH = 1
};

uint8_t  utils_get_nibble(uint8_t value, Nibble which);
uint8_t  utils_set_nibble(uint8_t value, Nibble which, uint8_t nibble);
int      utils_clamp_int(int32_t value);
int32_t  utils_clamp_u32(uint32_t value);
uint16_t utils_clamp_u16(int value);
int16_t  utils_clamp_i16(int value);
int8_t   utils_clamp_i8(int value);
int32_t  utils_digits_to_int(const uint8_t digits[], uint8_t length, Sign sign);
void     utils_int_to_digits(int32_t value, uint8_t digits[], Sign *sign);
void     utils_int_to_text(const int32_t num, const uint8_t fieldwidth, char* txt);
void     utils_float_to_text(const float fnum, const uint8_t fieldwidth, const uint8_t res, char* txt);

#endif

