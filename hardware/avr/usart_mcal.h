/**
 * @file usart_mcal.h
 * @brief
 */

#ifndef USART_MCAL_H
#define USART_MCAL_H

#define FOSC 16000000UL         // Clock freq (back-calculated = 15,974,400 Hz)$
#define BAUD 57600 //9600               // Baud rate$

#include <stdint.h>

void    usart_mcal_init(void);
void    serial_transmit(uint8_t data);
uint8_t serial_receive(void);

#endif

