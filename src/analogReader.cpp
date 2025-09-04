// analogReader

#include <Arduino.h>
#include <MultiFunctionShield.h>

MultiFunctionShield MFS;

void setup()
{
    pinMode(POT_PIN, INPUT);
    MFS.begin();
}

void loop()
{
    int potValue = analogRead(POT_PIN); // Reads a value from 0-1023
    MFS.Display(potValue);              // Display the value on the 7-segment display
}