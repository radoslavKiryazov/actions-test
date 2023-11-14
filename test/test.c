#include "dirtyword.h"
#include "fff.h"
#include "ledcontrol.h"
#include "uart.h"
#include <stdbool.h>
#include <unity.h>
DEFINE_FFF_GLOBALS;
#include "leds.h"

// faking LED
FAKE_VOID_FUNC(leds_init);
FAKE_VOID_FUNC(led1_off);
FAKE_VOID_FUNC(led1_on);
FAKE_VOID_FUNC(led2_off);
FAKE_VOID_FUNC(led2_on);

// faking uart
FAKE_VOID_FUNC(uart_init, int);
FAKE_VOID_FUNC(uart_send, char *);
FAKE_VALUE_FUNC(char *, uart_receive);

void setUp() {
  RESET_FAKE(leds_init);
  RESET_FAKE(led1_on);
  RESET_FAKE(led1_off);
  RESET_FAKE(uart_init);
  RESET_FAKE(uart_send);
  RESET_FAKE(uart_receive);
}
void tearDown() {}
// faking button
FAKE_VOID_FUNC(buttons_init);
FAKE_VALUE_FUNC(bool, button1_pressed); //,func argument goes here;
FAKE_VALUE_FUNC(bool, button2_pressed);

void test_dirtyword_init() {
  dirtyword_init();
  TEST_ASSERT_EQUAL(1, uart_init_fake.call_count);
}



void test_led_innit(void) {
  ledcontrol_init();
  TEST_ASSERT_EQUAL(1, leds_init_fake.call_count);
  TEST_ASSERT_EQUAL(1, buttons_init_fake.call_count);
}

void test_ledcontrol_button_not_pressed() {
  button1_pressed_fake.return_val = false;
  ledcontrol_evaluate();
  TEST_ASSERT_EQUAL(1, led1_off_fake.call_count);
  TEST_ASSERT_EQUAL(0, led1_on_fake.call_count);
}

void test_ledcontrol_button_pressed() {
  button1_pressed_fake.return_val = true;
  ledcontrol_evaluate();
  TEST_ASSERT_EQUAL(0, led1_off_fake.call_count);
  TEST_ASSERT_EQUAL(1, led1_on_fake.call_count);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_led_innit);
  RUN_TEST(test_ledcontrol_button_not_pressed);
  RUN_TEST(test_ledcontrol_button_pressed);
  RUN_TEST(test_dirtyword_init);

  return UNITY_END();
}
