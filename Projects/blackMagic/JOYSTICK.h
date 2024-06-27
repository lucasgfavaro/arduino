// Joystick.h
#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick {
  private:
    String name;
    int xPin;
    int YPin;
    int x;
    int y;
    String xPositionAndPower;
    String yPositionAndPower;
    int buttonPin;
    int buttonStatus;

  public:
    // Constructor
    Joystick(String joystickName, int joystickXPin, int joystickYPin, int joystickButtonPin) {
      name = joystickName;
      xPin = joystickXPin;
      YPin = joystickYPin;
      buttonPin = joystickButtonPin;
      pinMode(buttonPin, INPUT_PULLUP);
    }
    
  void calculatePositionAndPower(){
    
    x = analogRead(xPin);
    y = analogRead(YPin);

    if (480 <= x && x <= 521)
      xPositionAndPower = "C-0";
    else if (x < 480)
      xPositionAndPower = "L-" + String(map(x, 0, 479, 255, 0));
    else
      xPositionAndPower = "R-" + String(map(x, 522, 1023, 0, 255));

    if (480 <= y && y <= 521)
      yPositionAndPower =  "C-0";
    else if (y < 480)
      yPositionAndPower = "D-" + String(map(y, 0, 479, 255, 0));
    else if (y > 520)
      yPositionAndPower = "U-" + String(map(y, 522, 1023, 0, 255));

     buttonStatus =  digitalRead(buttonPin);
  }

  String getXPositionAndPower() {
    return xPositionAndPower;
  }

  String getYPositionAndPower() {
    return yPositionAndPower;
  }

  String toString() {
    return name + " X: " + getXPositionAndPower() + " - Y:" + getYPositionAndPower() + " B: " + buttonStatus;
  }

};

#endif