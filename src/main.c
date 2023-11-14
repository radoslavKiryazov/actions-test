#include "dirtyword.h"
#include "ledcontrol.h"
#include "leds.h"
  #include "threshold.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

void func() {
  led1_on();
  ms_delay(1000);
  led1_off();
}

int main() {}
leds_init();
timer_init_a(func, 2000);

while (1) {
  // not too critical task

  cli();
  // critical task
  sei();
}
// void func(int a) { printf("The value %d is above the threshold\n", a); }
// int main(int argc, char const *argv[]) {
//   threshold_init(func, 50);
//   threshold_evaluate(60);
//   threshold_evaluate(40);
// }

// int main(int argc, char const *argv[]) {
//   ledcontrol_init();

//   while (1) {
//     ledcontrol_evaluate();
//   }

//   return 0;
// }
