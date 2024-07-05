// Joystick.h
#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class MiniJoystick {
private:
  String name;
  int xPin;
  int YPin;
  int buttonPin;
  char xDirection;
  long xPower;
  char yDirection;
  long yPower;
  boolean buttonOn = false;

public:
  // Constructor
  MiniJoystick(String joystickName, int joystickXPin, int joystickYPin, int joystickButtonPin) {
    name = joystickName;
    xPin = joystickXPin;
    YPin = joystickYPin;
    buttonPin = joystickButtonPin;
    pinMode(buttonPin, INPUT_PULLUP);
  }

  char getXDirection() {
    return xDirection;
  }

  long getXPower() {
    return xPower;
  }

  char getYDirection() {
    return yDirection;
  }

  long getYPower() {
    return yPower;
  }

  boolean buttonIsOn() {
    return buttonOn;
  }

  void refreshStatus() {
    int x = analogRead(xPin);
    int y = analogRead(YPin);

    if (480 <= x && x <= 521) {
      xPower = 0;
      xDirection = 'C';
    } else if (x < 480) {
      xPower = map(x, 0, 479, 255, 0);
      xDirection = 'L';
    } else {
      xPower = map(x, 522, 1023, 0, 255);
      xDirection = 'R';
    }

    if (480 <= y && y <= 521) {
      yPower = 0;
      yDirection = 'C';
    } else if (y < 480) {
      yPower = map(y, 0, 479, 255, 0);
      yDirection = 'D';
    } else if (y > 520) {
      yPower = map(y, 522, 1023, 0, 255);
      yDirection = 'U';
    }

    if (digitalRead(buttonPin) == 1) {
      buttonOn = false;
    } else {
      buttonOn = true;
    }
  }

  String toString() {
    return name + " X: " + xDirection + " " + xPower + " - Y:" + yDirection + " " + yPower + " B: " + buttonOn;
  }
};

#endif