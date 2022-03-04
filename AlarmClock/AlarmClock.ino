


/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-piezo-buzzer
 */

#include "pitches.h"

const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int BUZZER_PIN = 3; // Arduino pin connected to Buzzer's pin

// notes in the melody:
int melody[] = {
  NOTE_D8, NOTE_D8, NOTE_D8, NOTE_D8, NOTE_D8, NOTE_D8, NOTE_D8, NOTE_D8,
};

// note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
int noteDurations[] = {
  16, 16, 16, 16, 16, 16, 16, 16, 16
};

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // read new state

  if (buttonState == LOW) { // button is pressed
    Serial.println("The button is being pressed");
    buzzer();
  }
}

void buzzer() {
  // iterate over the notes of the melody:
  int size = sizeof(noteDurations) / sizeof(int);

  for (int thisNote = 0; thisNote < size; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER_PIN);
  }
}
