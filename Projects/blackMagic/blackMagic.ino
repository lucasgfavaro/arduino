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
#include "BUTTON.h"

const int rightJoystickPinX = A0;
const int rightJoystickPinY = A1;
const int rightJoystickButton = 12;

const int leftJoystickPinX = A2;
const int leftJoystickPinY = A3;
const int leftJoystickButton = 11;

const int leftButtonPin = 10;
const int rightButtonPin = 4;

Joystick rightJoystick("RIGHT JOYSTICK", rightJoystickPinX, rightJoystickPinY, rightJoystickButton);
Joystick leftJoystick("LEFT JOYSTICK" , leftJoystickPinX, leftJoystickPinY, leftJoystickButton);
Button rightButton("RIGHT BUTTON", rightButtonPin);
Button leftButton("LEFT BUTTON", leftButtonPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  rightJoystick.calculatePositionAndPower();
  leftJoystick.calculatePositionAndPower();
  rightButton.calculateStatus();
  leftButton.calculateStatus();
  printJoystickStatus();
  delay(1000);
}

void printJoystickStatus(){
    Serial.print(rightJoystick.toString() + " " + leftJoystick.toString() + " " + rightButton.toString() + " " + leftButton.toString() + "\r\n" );
}





