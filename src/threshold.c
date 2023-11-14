#include "threshold.h"
#include <stddef.h>

static threshold_callback_t callback_static = NULL;
int threshold_value = 0;

void threshold_init(threshold_callback_t callback, int value) {
  callback_static = callback;
  threshold_value = value;
};

void threshold_evaluate(int value) {
  if (threshold_value < value)
    callback_static(value);
}