#include <Arduino.h>
#include <MultiFunctionShield.h>

#define BUTTON_COUNT 3
#define LED_COUNT 4

#define Led(index) (LED_1_PIN - index)
#define Button(index) (BUTTON_1_PIN + index)

#define LedClose(led) digitalWrite(led, HIGH)
#define LedOpen(led) digitalWrite(led, LOW)

#define ButtonPressed(button) (digitalRead(button) == LOW)