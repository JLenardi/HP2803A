/**
 * @file utils_crc.h
 * @brief
 */

#ifndef UTILS_CRC_H
#define UTILS_CRC_H

#include <stdint.h>

uint8_t crc8(const uint8_t * data, uint16_t len);
uint16_t crc16(const uint8_t *data, uint16_t len);

#endif

