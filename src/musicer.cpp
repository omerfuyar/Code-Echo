// musicer

#include <Arduino.h>

#define PIN_BUZZER 13

#define NOTE_DURATION_DELAY_MULTIPLIER 1.15f

#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659

#define NOTE_WHOLE 1
#define NOTE_HALF 2
#define NOTE_QUARTER 4
#define NOTE_EIGHTH 8

const int baseNoteDuration = 2048; // Corresponds to a whole note

typedef struct
{
    uint16_t frequency;
    uint8_t durationDivider;
} Note;

Note melodyPart1[] = {
    {NOTE_A4, 8}, //
    {NOTE_GS4, 8},
    {NOTE_A4, 8},
    {NOTE_B4, 8},
    {NOTE_B4, 8},
    {NOTE_B4, 4},
    {NOTE_B4, 4},
    {NOTE_D5, 8},
    {NOTE_C5, 8},
    {NOTE_B4, 8},
    {NOTE_A4, 4},
    {NOTE_B4, 8},
    {NOTE_B4, 8},
    {NOTE_B4, 8},
    {NOTE_E5, 8},
    {NOTE_D5, 8},
    {NOTE_C5, 8},
    {NOTE_B4, 8},
    {NOTE_A4, 8},
    {NOTE_B4, 2}};

Note melodyPart2[] = {
    {NOTE_B4, 8}, //
    {NOTE_C5, 8},
    {NOTE_B4, 8},
    {NOTE_A4, 8},
    {NOTE_A4, 8},
    {NOTE_B4, 8},
    {NOTE_C5, 4},
    {NOTE_B4, 4},
    {NOTE_C5, 4},
    {NOTE_A4, 8},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_F4, 2},
    {NOTE_F4, 8},
    {NOTE_F4, 8},
    {NOTE_GS4, 8},
    {NOTE_B4, 8},
    {NOTE_A4, 8},
    {NOTE_G4, 8},
    {NOTE_F4, 8},
    {NOTE_E5, 2}};

Note melodyPart3[] = {
    {NOTE_A4, 8}, //
    {NOTE_A4, 8},
    {NOTE_A4, 8},
    {NOTE_A4, 8},
    {NOTE_A4, 8},
    {NOTE_B4, 8},
    {NOTE_C5, 4},
    {NOTE_C5, 4},
    {NOTE_B4, 4},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_B4, 8},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_B4, 8},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_C5, 8},
    {NOTE_B4, 8},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_F4, 8},
    {NOTE_F4, 8},
    {NOTE_F4, 8},
    {NOTE_F4, 8},
    {NOTE_F4, 8},
    {NOTE_GS4, 8},
    {NOTE_A4, 8},
    {NOTE_A4, 4},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_F4, 8},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_F4, 8},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_F4, 8},
    {NOTE_B4, 8},
    {NOTE_A4, 8},
    {NOTE_GS4, 8},
    {NOTE_F4, 8},
    {NOTE_E5, 2}};

void playMelody(Note *notes, uint8_t noteCount)
{
    for (int i = 0; i < noteCount; i++)
    {
        int noteDuration = baseNoteDuration / notes[i].durationDivider;
        tone(PIN_BUZZER, notes[i].frequency, noteDuration);

        delay(noteDuration * NOTE_DURATION_DELAY_MULTIPLIER);

        noTone(PIN_BUZZER);
    }
}

void setup()
{
    pinMode(PIN_BUZZER, OUTPUT);
}

void loop()
{
    playMelody(melodyPart1, sizeof(melodyPart1) / sizeof(Note));
    delay(500);
    playMelody(melodyPart1, sizeof(melodyPart1) / sizeof(Note));
    delay(1000);

    playMelody(melodyPart2, sizeof(melodyPart2) / sizeof(Note));
    delay(500);
    playMelody(melodyPart2, sizeof(melodyPart2) / sizeof(Note));
    delay(1000);

    playMelody(melodyPart3, sizeof(melodyPart3) / sizeof(Note));
    delay(500);
    playMelody(melodyPart3, sizeof(melodyPart3) / sizeof(Note));
    delay(5000);
}