/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"
const int buttonPin = 9;
int state = 0;

// notes in the melody:
int melody[] = {
  NOTE_A4, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_B4, NOTE_C3, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_E4, NOTE_E3, NOTE_D3, NOTE_E3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 2, 8, 8, 2, 8, 8, 2, 2, 4,4, 2, 8, 1
};

int melody2[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {
  8, 4, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
   // iterate over the notes of the melody:
   state = digitalRead(9);
   if(state == 0){
        for (int thisNote = 0; thisNote < 8; thisNote++) {
    
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
      delay(200);
    }

    else if(state == 1){
        for (int thisNote = 0; thisNote < 8; thisNote++) {
    
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations2[thisNote];
        tone(8, melody2[thisNote], noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
      delay(200);
    }
  Serial.println(state);
}
