// Joystick.h
#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick {
  private:
    String name;
    int pinX;
    int pinY;
    int pinButton;
    int x;
    int y;
    String xPositionAndPower;
    String yPositionAndPower;
    int buttonStatus;

  public:
    // Constructor
    Joystick(String joystickName, int joystickPinX, int joystickPinY, int joystickPinButton) {
      name = joystickName;
      pinX = joystickPinX;
      pinY = joystickPinY;
      pinButton = joystickPinButton;
      pinMode(pinButton, INPUT_PULLUP);
    }
    
  void calculatePositionAndPower(){
    
    x = analogRead(pinX);
    y = analogRead(pinY);

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

     buttonStatus =  digitalRead(pinButton);
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