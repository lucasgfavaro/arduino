/* 
  This program takes values from joytick and outputs the following commands

  [directionOverAxis]"-"[intensity 0-255]

  directionOverAxis X
    *R = Right
    *L = Left

  directionOverAxis Y
    *U = Up
    *D = Down

*/
#include "JOYSTICK.h"

const int rightJoystickPinX = A0;
const int rightJoystickPinY = A1;
const int rightJoystickButton = 12;

const int leftJoystickPinX = A2;
const int leftJoystickPinY = A3;
const int leftJoystickButton = 11;

Joystick rightJoystick("RIGHT", rightJoystickPinX, rightJoystickPinY, rightJoystickButton);
Joystick leftJoystick("LEFT", leftJoystickPinX, leftJoystickPinY, leftJoystickButton);

void setup() {
  Serial.begin(9600);
}

void loop() {
  rightJoystick.calculatePositionAndPower();
  leftJoystick.calculatePositionAndPower();
  Serial.print(rightJoystick.toString() + " " +leftJoystick.toString() + "\r\n" );

  delay(100);
}





