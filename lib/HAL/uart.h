#pragma once
void uart_init(int baudrate);
void uart_send(char *data);
char *uart_receive();