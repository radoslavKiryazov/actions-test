#ifndef NATIVE_TEST
#include "leds.h"
#include <Arduino.h>
#include <avr/io.h>

void leds_init() {
  DDRB |= (1 << PB0);
  DDRB |= (1 << PB3);
}
void led1_on() { PORTB |= (1 << PB0); }
void led1_off() { PORTB &= ~(1 << PB0); }
void led2_on() { PORTB |= (1 << PB3); }
void led2_off() { PORTB &= ~(1 << PB3); }

#endif