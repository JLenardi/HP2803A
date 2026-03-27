/**
 * @file timer_mcal.h
 * @brief Initializes Timer 0 (periodic debounce tick) and Timer 1 (1 Hz base timer).
 */

#ifndef TIMER_MCAL_H_
#define TIMER_MCAL_H_

/**
 * Configures Timer 0 and Timer 1 in CTC mode, sets their prescalers and compare values,
 * and enables interrupts for the required timing operations.
 *
 * @note
 * The complete low-level (re-)initialization sequence for Timer 0 is:
 * @code
 * uint8_t s = SREG;
 * cli();
 * TIMSK0 &= ~(1 << OCIE0A);
 * TCCR0B  = 0;
 * TCCR0A  = (1 << WGM01);
 * OCR0A   = 249;
 * TCNT0   = 0;
 * TIFR0   = (1 << OCF0A);
 * TIMSK0 |= (1 << OCIE0A);
 * TCCR0B  = (1 << CS02);
 * SREG = s;
 * @endcode
 */
void timer_mcal_init(void);
void start_timer0(void);
void start_timer1(void);
void stop_timer0(void);
void stop_timer1(void);

#endif

