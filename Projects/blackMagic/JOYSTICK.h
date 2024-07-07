// MiniJoystick.h
#ifndef MINIJOYSTICK_H
#define MINIJOYSTICK_H

#include <Arduino.h>

class MiniJoystick {
private:
  int xPin;
  int YPin;
  int buttonPin;
  char xDirection;
  char xPower[4];
  char yDirection;
  char yPower[4];
  boolean buttonOn = false;

public:
  // Constructor
  MiniJoystick(int joystickXPin, int joystickYPin, int joystickButtonPin) {
    xPin = joystickXPin;
    YPin = joystickYPin;
    buttonPin = joystickButtonPin;
    pinMode(buttonPin, INPUT_PULLUP);
  }

  char getXDirection() {
    return xDirection;
  }

  String getXPower() {
    return xPower;
  }

  char getYDirection() {
    return yDirection;
  }

  String getYPower() {
    return yPower;
  }

  boolean buttonIsOn() {
    return buttonOn;
  }

  String getState() {
    int xP;
    int yP;
    int x = analogRead(xPin);
    int y = analogRead(YPin);

    if (480 <= x && x <= 521) {
      xP = 0;
      xDirection = 'C';
    } else if (x < 480) {
      xP = map(x, 0, 479, 255, 0);
      xDirection = 'L';
    } else {
      xP = map(x, 522, 1023, 0, 255);
      xDirection = 'R';
    }
    sprintf(xPower, "%03d", xP);
    if (480 <= y && y <= 521) {
      yP = 0;
      yDirection = 'C';
    } else if (y < 480) {
      yP = map(y, 0, 479, 255, 0);
      yDirection = 'D';
    } else if (y > 520) {
      yP = map(y, 522, 1023, 0, 255);
      yDirection = 'U';
    }
    sprintf(yPower, "%03d", yP);
    if (digitalRead(buttonPin) == 1) {
      buttonOn = false;
    } else {
      buttonOn = true;
    }

    return xDirection + String(xPower) + yDirection + String(yPower) + buttonOn;
  }
};

#endif