// Characters.h
#ifndef CHARACTERS_H
#define CHARACTERS_H

byte centered[8] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000
};

byte down[8] = {
  B00000,
  B00000,
  B00000,
  B10001,
  B01010,
  B00100,
  B00000,
  B00000
};

byte up[8] = {
  B00000,
  B00100,
  B01010,
  B10001,
  B00000,
  B00000,
  B00000,
  B00000
};

byte buttonOff[8] = {
  B00000,
  B01110,
  B11011,
  B10001,
  B10001,
  B11011,
  B01110,
  B00000
};

byte buttonOn[8] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000
};

byte toggleSwitchOff[8] = {
  B10000,
  B01000,
  B00100,
  B01110,
  B11111,
  B10001,
  B10001,
  B11111
};

byte toggleSwitchOn[8] = {
  B00001,
  B00010,
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111
};

#endif