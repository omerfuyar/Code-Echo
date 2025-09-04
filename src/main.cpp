// servo

#include <Arduino.h>
#include <Servo.h>

#define SERVO_STEP_DURATION 100

#define PIN_SERVO1 9

Servo servo9;

void setup()
{
    servo9.attach(PIN_SERVO1);
    servo9.write(90); // stop
    Serial.begin(9600);
}

void loop()
{
    // servo9.write(0); // turn one way
    // delay(1000);
    // servo9.write(90); // stop
    // delay(1000);
    // servo9.write(180); // turn another way
    // delay(1000);
    // servo9.write(90); // stop
    // delay(1000);

    for (uint8_t i = 0; i < 180; i++)
    {
        servo9.write(i); // write clamps the parameter to 0-180
        Serial.println(i);
        delay(SERVO_STEP_DURATION);
    }

    for (uint8_t i = 180; i > 0; i--)
    {
        servo9.write(i);
        Serial.println(i);
        delay(SERVO_STEP_DURATION);
    }
}
