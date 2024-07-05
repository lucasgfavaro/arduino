
// Button.h
#ifndef CHARACTERS_H
#define CHARACTERS_H

byte rightArrow[] = {
  B00000,
  B00100,
  B00010,
  B11111,
  B00010,
  B00100,
  B00000,
  B00000
};

byte leftArrow[] = {
  B00000,
  B00100,
  B01000,
  B11111,
  B01000,
  B00100,
  B00000,
  B00000
};

byte downArrow[] = {
  B00000,
  B00100,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100,
  B00000
};

byte upArrow[] = {
  B00000,
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00100,
  B00000
};

byte buttonOff[] = {
  B00000,
  B01110,
  B11011,
  B10001,
  B10001,
  B11011,
  B01110,
  B00000
};

byte buttonOn[] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000
};

byte toggleSwitchOff[] = {
  B10000,
  B01000,
  B00100,
  B01110,
  B11111,
  B10001,
  B10001,
  B11111
};

byte toggleSwitchOn[] = {
  B00001,
  B00010,
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111
};

byte centered[] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000
};

#endif