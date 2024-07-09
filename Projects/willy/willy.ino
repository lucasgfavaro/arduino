/*
  AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install
*/
#include <AFMotor.h>
#include <SoftwareSerial.h>
#include "BLACKMAGIC_RC_STATE.h"

SoftwareSerial bluetoothSerial(9, 10);  // RX, TX
AF_DCMotor leftMotor1(1, MOTOR12_64KHZ);
AF_DCMotor leftMotor2(2, MOTOR12_64KHZ);
AF_DCMotor rightMotor1(3, MOTOR34_64KHZ);
AF_DCMotor rightMotor2(4, MOTOR34_64KHZ);

boolean debug = false;
BlackMagicRemoteControlState remoteControlState;

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(38400);
}

void loop() {
  remoteControlState.setStateFromCommand(bluetoothSerial.readStringUntil('\n'));
  processCommand(&remoteControlState);
}

void processCommand(BlackMagicRemoteControlState* remoteControlState) {
  
  if (debug)
    Serial.println("command:"+remoteControlState->getState());

  if (remoteControlState->getLeftButtonOn()) {
    
    Serial.println("Slalom");
    startSlalom();
    
  } else {
    //Serial.println("Normal");
    Stop();
    if (remoteControlState->getLeftMiniJoystickYDirection() == 'U') {
      forward(remoteControlState->getLeftMiniJoystickYPower(), remoteControlState->getRightMiniJoystickXDirection(), remoteControlState->getRightMiniJoystickXPower());
    } else if (remoteControlState->getLeftMiniJoystickYDirection() == 'D') {
      backward(remoteControlState->getLeftMiniJoystickYPower(), remoteControlState->getRightMiniJoystickXDirection(), remoteControlState->getRightMiniJoystickXPower());
    } else if (remoteControlState->getRightMiniJoystickXDirection() == 'R') {
      right(remoteControlState->getRightMiniJoystickXPower());
    } else if (remoteControlState->getRightMiniJoystickXDirection() == 'L') {
      left(remoteControlState->getRightMiniJoystickXPower());
    }
    //Serial.println("EndNormal");
  }
}

void startSlalom() {

  String forwardSpeed = "255";
  char xPower[4] = "000";

  forward(forwardSpeed, 'C', xPower);
  delay(100);

  for (int xP = 100; xP < 255; xP += 10) {
    sprintf(xPower, "%03d", xP);
    forward(forwardSpeed, 'R', xPower);
    delay(50);
  }

  forward(forwardSpeed, 'C', xPower);
  delay(100);

  for (int xP = 100; xP < 255; xP += 10) {
    sprintf(xPower, "%03d", xP);
    forward(forwardSpeed, 'L', xPower);
    delay(50);
  }
}

void forward(String power, char steering, String steeringPower) {
  int speed = map(power.toInt(), 0, 255, 100, 255);
  int speedLeft = speed;
  int speedRight = speed;

  if (steering == 'R')
    speedRight = speed - map(steeringPower.toInt(), 0, 255, 100, 254);
  if (steering == 'L')
    speedLeft = speed - map(steeringPower.toInt(), 0, 255, 100, 254);

  if (!debug) {
    leftMotor1.run(FORWARD);
    rightMotor1.run(FORWARD);
    leftMotor2.run(FORWARD);
    rightMotor2.run(FORWARD);
    leftMotor1.setSpeed(speedLeft);
    rightMotor1.setSpeed(speedRight);
    leftMotor2.setSpeed(speedLeft);
    rightMotor2.setSpeed(speedRight);
  } else Serial.println("FORWARD: " + String(speedLeft) + " | " + String(speedRight));
}

void backward(String power, char steering, String steeringPower) {
  int speed = map(power.toInt(), 0, 255, 80, 255);
  int speedLeft = speed;
  int speedRight = speed;

  if (steering == 'R')
    speedRight = speed - map(steeringPower.toInt(), 0, 255, 80, 254);
  if (steering == 'L')
    speedLeft = speed - map(steeringPower.toInt(), 0, 255, 80, 254);

  if (!debug) {
    leftMotor1.run(BACKWARD);
    rightMotor1.run(BACKWARD);
    leftMotor2.run(BACKWARD);
    rightMotor2.run(BACKWARD);
    leftMotor1.setSpeed(speedLeft);
    rightMotor1.setSpeed(speedRight);
    leftMotor2.setSpeed(speedLeft);
    rightMotor2.setSpeed(speedRight);
  } else
    Serial.println("BACKWARD:" + String(speedLeft) + " | " + String(speedRight));
}

void left(String power) {
  int speed = map(power.toInt(), 0, 255, 80, 255);
  if (!debug) {
    leftMotor1.run(BACKWARD);
    rightMotor1.run(FORWARD);
    leftMotor2.run(BACKWARD);
    rightMotor2.run(FORWARD);
    leftMotor1.setSpeed(speed);
    rightMotor1.setSpeed(speed);
    leftMotor2.setSpeed(speed);
    rightMotor2.setSpeed(speed);
  } else
    Serial.println("LEFT:" + String(speed));
}

void right(String power) {
  int speed = map(power.toInt(), 0, 255, 80, 255);
  if (!debug) {
    leftMotor1.run(FORWARD);
    rightMotor1.run(BACKWARD);
    leftMotor2.run(FORWARD);
    rightMotor2.run(BACKWARD);
    leftMotor1.setSpeed(speed);
    rightMotor1.setSpeed(speed);
    leftMotor2.setSpeed(speed);
    rightMotor2.setSpeed(speed);
  } else
    Serial.println("RIGHT" + String(speed));
}

void Stop() {
  if (!debug) {
    leftMotor1.run(RELEASE);
    rightMotor1.run(RELEASE);
    leftMotor2.run(RELEASE);
    rightMotor2.run(RELEASE);
    leftMotor1.setSpeed(0);
    rightMotor1.setSpeed(0);
    leftMotor2.setSpeed(0);
    rightMotor2.setSpeed(0);
  } else
    Serial.println("STOP");
}
