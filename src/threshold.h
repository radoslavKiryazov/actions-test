#pragma once
typedef void (*threshold_callback_t)(int);

void threshold_init(threshold_callback_t callback, int value);

void threshold_evaluate(int value);