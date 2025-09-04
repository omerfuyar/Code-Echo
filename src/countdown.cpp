// countdown

#include "main.h"

#define WAIT_TIME_MS 100

#define COUNTDOWN_MIN 1
#define COUNTDOWN_SEC 15

boolean buttonsPressed[BUTTON_COUNT] = {false, false, false};

MultiFunctionShield MFS;
uint64_t totalMillis = COUNTDOWN_MIN * 60000 + COUNTDOWN_SEC * 1000;
uint64_t milliseconds = 0;

void setup()
{
    for (uint8_t i = 0; i < BUTTON_COUNT; i++)
    {
        pinMode(Button(i), INPUT_PULLUP);
    }

    MFS.begin();
}

void loop()
{
    milliseconds = totalMillis - millis();

    if (milliseconds <= 0)
    {
        MFS.Clear();
    }
    else
    {
        MFS.Display(((milliseconds - (milliseconds % 60000)) / 60000) * 100 + ((milliseconds % 60000) / 1000));
    }
}