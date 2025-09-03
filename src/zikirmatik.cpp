#include <Arduino.h>
#include <MultiFunctionShield.h>

#define BUTTON_COUNT 3
#define LED_COUNT 4
#define WAIT_TIME_MS 100

#define BUTTON_INDEX_SELECT 0
#define BUTTON_INDEX_INCREMENT 1
#define BUTTON_INDEX_RESET 2

#define LedClose(led) digitalWrite(led, HIGH)
#define LedOpen(led) digitalWrite(led, LOW)

#define ButtonPressed(button) (digitalRead(button) == LOW)

uint8_t LEDS[LED_COUNT] = {LED_1_PIN, LED_2_PIN, LED_3_PIN, LED_4_PIN};
uint8_t BUTTONS[BUTTON_COUNT] = {BUTTON_1_PIN, BUTTON_2_PIN, BUTTON_3_PIN};
boolean BUTTONS_PRESSED_LAST_LOOP[BUTTON_COUNT] = {false, false, false};

MultiFunctionShield MFS;
int16_t counterIndex = 0;
int16_t counters[LED_COUNT];

void setup()
{
	MFS.begin();

	for (uint8_t i = 0; i < LED_COUNT; i++)
	{
		pinMode(LEDS[i], OUTPUT);
		LedClose(LEDS[i]);
	}

	for (uint8_t i = 0; i < BUTTON_COUNT; i++)
	{
		pinMode(BUTTONS[i], INPUT_PULLUP);
	}

	for (uint8_t i = 0; i < LED_COUNT; i++)
	{
		counters[i] = 0;
	}

	LedOpen(LEDS[counterIndex]);
	MFS.Display(counters[counterIndex]);
}

void loop()
{
	if (ButtonPressed(BUTTONS[BUTTON_INDEX_SELECT]) && !BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_SELECT])
	{
		counterIndex = (counterIndex + 1) % LED_COUNT;

		for (uint8_t i = 0; i < LED_COUNT; i++)
		{
			LedClose(LEDS[i]);
		}

		LedOpen(LEDS[counterIndex]);

		BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_SELECT] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!ButtonPressed(BUTTONS[BUTTON_INDEX_SELECT]))
	{
		BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_SELECT] = false;
	}

	if (ButtonPressed(BUTTONS[BUTTON_INDEX_INCREMENT]) && !BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_INCREMENT])
	{
		counters[counterIndex]++;

		BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_INCREMENT] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!ButtonPressed(BUTTONS[BUTTON_INDEX_INCREMENT]))
	{
		BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_INCREMENT] = false;
	}

	if (ButtonPressed(BUTTONS[BUTTON_INDEX_RESET]) && !BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_RESET])
	{
		counters[counterIndex] = 0;

		BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_RESET] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!ButtonPressed(BUTTONS[BUTTON_INDEX_RESET]))
	{
		BUTTONS_PRESSED_LAST_LOOP[BUTTON_INDEX_RESET] = false;
	}
}