
#include "pitches.h"

const int buzzer = 4; // Buzzer connected to D4

// melodies and notes
int melody1[8] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int melody2[8] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0
};

int melody3[8] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Only for debugging
  pinMode(buzzer, OUTPUT);
}

void playMelody1() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody1[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  noTone(buzzer);
}

void playMelody2() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody2[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  noTone(buzzer);
}

void playMelody3() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody3[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  noTone(buzzer);
}

void switchMelody(int m) {
  if (m == 1) {
    playMelody1();
  }
  else if (m == 2) {
    playMelody2();
  }
  else if (m == 3) {
    playMelody3();
  }
}

int thisMelody = 1;

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = analogRead(A0);  // read vibration value
  Serial.println(sensor);

  if (thisMelody > 3) {
    thisMelody = 1;
  }

  if (sensor > 1022) {
    switchMelody(thisMelody);
    thisMelody += 1;
    delay(1000);
  }
  else { // stop the tone playing
    noTone(buzzer);
  }
  noTone(buzzer);
}
