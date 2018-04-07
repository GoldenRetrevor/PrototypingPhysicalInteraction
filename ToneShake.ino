
#include "pitches.h"

const int buzzer = 8; // Buzzer connected to pin 8
int sensor; // Sensor connected to pin 10

// notes in the melody
int melodys[3][8] = {
  {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4},
  {NOTE_AS1, NOTE_E2, NOTE_CS1, NOTE_C5, NOTE_E6, 0, NOTE_FS5, NOTE_G2},
  {NOTE_D7, NOTE_A5, NOTE_DS6, NOTE_B6, NOTE_A4, 0, NOTE_FS3, NOTE_DS2}
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Only for debugging
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor = analogRead(A0);
  if (sensor < 1022) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
  
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(buzzer, melodys[thisMelody][thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      thisMelody += 1;
      delay(pauseBetweenNotes);
    }
  }
  else { // stop the tone playing
      noTone(buzzer);
  }
}
