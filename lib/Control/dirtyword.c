#include "dirtyword.h"
#include "uart.h"
#include <string.h>

void dirtyword_init() { uart_init(9600); }

void dirtyword_echo(char *dirtyword) {
  char str[128];
  for (int i = 0; i < 128; i++) {
    str[i] = '\0';
  }
  strcpy(str, uart_receive());
  strcat(str, dirtyword);
  uart_send(str);
}