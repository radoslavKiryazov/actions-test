#include "ledcontrol.h"
#include "button.h"
#include "leds.h"

void ledcontrol_init() {
  leds_init();
  buttons_init();
}

void ledcontrol_evaluate() {
  if (button1_pressed()) {
    led1_on();
  } else {
    led1_off();
  }

  if (button2_pressed()) {
    led2_on();
  } else {
    led2_off();
  }
}