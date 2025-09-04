// zikirmatik

#include <Arduino.h>
#include <MultiFunctionShield.h>

#define DigitalClose(pin) digitalWrite(pin, HIGH)
#define DigitalOpen(pin) digitalWrite(pin, LOW)

#define DigitalIsActive(pin) (digitalRead(pin) == LOW)

#define BUTTON_COUNT 3
#define LED_COUNT 4

#define Led(index) (LED_1_PIN - index)
#define Button(index) (BUTTON_1_PIN + index)

#define WAIT_TIME_MS 100

#define BUTTON_INDEX_SELECT 0
#define BUTTON_INDEX_INCREMENT 1
#define BUTTON_INDEX_RESET 2

boolean buttonsPressed[BUTTON_COUNT] = {false, false, false};

MultiFunctionShield MFS;
int16_t counterIndex = 0;
int16_t counters[LED_COUNT];

void setup()
{
	MFS.begin();

	for (uint8_t i = 0; i < LED_COUNT; i++)
	{
		pinMode(Led(i), OUTPUT);
		DigitalClose(Led(i));
	}

	for (uint8_t i = 0; i < BUTTON_COUNT; i++)
	{
		pinMode(Button(i), INPUT_PULLUP);
	}

	for (uint8_t i = 0; i < LED_COUNT; i++)
	{
		counters[i] = 0;
	}

	DigitalOpen(Led(counterIndex));
	MFS.Display(counters[counterIndex]);
}

void loop()
{
	if (DigitalIsActive(Button(BUTTON_INDEX_SELECT)) && !buttonsPressed[BUTTON_INDEX_SELECT])
	{
		counterIndex = (counterIndex + 1) % LED_COUNT;

		for (uint8_t i = 0; i < LED_COUNT; i++)
		{
			DigitalClose(Led(i));
		}

		DigitalClose(Led(counterIndex));

		buttonsPressed[BUTTON_INDEX_SELECT] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!DigitalIsActive(Button(BUTTON_INDEX_SELECT)))
	{
		buttonsPressed[BUTTON_INDEX_SELECT] = false;
	}

	if (DigitalIsActive(Button(BUTTON_INDEX_INCREMENT)) && !buttonsPressed[BUTTON_INDEX_INCREMENT])
	{
		counters[counterIndex]++;

		buttonsPressed[BUTTON_INDEX_INCREMENT] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!DigitalIsActive(Button(BUTTON_INDEX_INCREMENT)))
	{
		buttonsPressed[BUTTON_INDEX_INCREMENT] = false;
	}

	if (DigitalIsActive(Button(BUTTON_INDEX_RESET)) && !buttonsPressed[BUTTON_INDEX_RESET])
	{
		counters[counterIndex] = 0;

		buttonsPressed[BUTTON_INDEX_RESET] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!DigitalIsActive(Button(BUTTON_INDEX_RESET)))
	{
		buttonsPressed[BUTTON_INDEX_RESET] = false;
	}
}