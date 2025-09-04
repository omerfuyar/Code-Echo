// zikirmatik

#include "main.h"

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
		LedClose(Led(i));
	}

	for (uint8_t i = 0; i < BUTTON_COUNT; i++)
	{
		pinMode(Button(i), INPUT_PULLUP);
	}

	for (uint8_t i = 0; i < LED_COUNT; i++)
	{
		counters[i] = 0;
	}

	LedOpen(Led(counterIndex));
	MFS.Display(counters[counterIndex]);
}

void loop()
{
	if (ButtonPressed(Button(BUTTON_INDEX_SELECT)) && !buttonsPressed[BUTTON_INDEX_SELECT])
	{
		counterIndex = (counterIndex + 1) % LED_COUNT;

		for (uint8_t i = 0; i < LED_COUNT; i++)
		{
			LedClose(Led(i));
		}

		LedOpen(Led(counterIndex));

		buttonsPressed[BUTTON_INDEX_SELECT] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!ButtonPressed(Button(BUTTON_INDEX_SELECT)))
	{
		buttonsPressed[BUTTON_INDEX_SELECT] = false;
	}

	if (ButtonPressed(Button(BUTTON_INDEX_INCREMENT)) && !buttonsPressed[BUTTON_INDEX_INCREMENT])
	{
		counters[counterIndex]++;

		buttonsPressed[BUTTON_INDEX_INCREMENT] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!ButtonPressed(Button(BUTTON_INDEX_INCREMENT)))
	{
		buttonsPressed[BUTTON_INDEX_INCREMENT] = false;
	}

	if (ButtonPressed(Button(BUTTON_INDEX_RESET)) && !buttonsPressed[BUTTON_INDEX_RESET])
	{
		counters[counterIndex] = 0;

		buttonsPressed[BUTTON_INDEX_RESET] = true;

		MFS.Display(counters[counterIndex]);
	}
	else if (!ButtonPressed(Button(BUTTON_INDEX_RESET)))
	{
		buttonsPressed[BUTTON_INDEX_RESET] = false;
	}
}