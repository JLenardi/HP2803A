/**
 * @file sys_output.h
 * @brief
 */

#ifndef SYS_OUTPUT_H
#define SYS_OUTPUT_H

#include <stdint.h>

void sys_transmit_results(void);
void sys_output_transmit(uint8_t byte);
void sys_output_string(const char * str);

const char * get_output_buf(void);
char * get_output_buf_mutable(void);

#endif

