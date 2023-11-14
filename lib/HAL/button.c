#ifndef NATIVE_TEST
#include "button.h"
#include <Arduino.h>
#include <avr/io.h>
#include <stdbool.h>

void buttons_init() {
  DDRA &= ~(1 << PA1);
  DDRA &= ~(1 << PA5);
  // set the PA0 to be an input because the button is
  PORTA |= (1 << PA1);
  PORTA |= (1 << PA5);
}

bool button1_pressed() { return !(PINA & (1 << PA1)); }
bool button2_pressed() { return !(PINA & (1 << PA5)); }

#endif