/*
  AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install
*/


#include <AFMotor.h>
#include <SoftwareSerial.h>
#include "BLACKMAGIC_RC_STATE.h"

SoftwareSerial bluetoothSerial(9, 10);  // RX, TX

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR34_64KHZ);
AF_DCMotor motor4(4, MOTOR34_64KHZ);

char command;
int speed = 255;
int steeringSpeed = 130;

const int BUFFER_SIZE = 23;
char inputBuffer[BUFFER_SIZE];
int bufferIndex = 0;
BlackMagicRemoteControlState remoteControlState;

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(38400);
  Serial.println("OK");  //Set the baud rate to your Bluetooth module.
}

void loop() {
  while (bluetoothSerial.available() > 0) {
    char receivedChar = bluetoothSerial.read();
    if (bufferIndex < BUFFER_SIZE - 1) {
      inputBuffer[bufferIndex++] = receivedChar;
    }
    if (receivedChar == '\n') {
      inputBuffer[bufferIndex] = '\0';      
      processCommand(inputBuffer);
      bufferIndex = 0;
    }
  }
}

void processCommand(char* command) {
  Serial.println("COMAND:" + String(command));
  remoteControlState.setStateFromCommand(String(command));
  Serial.println("SSTATE:" + remoteControlState.getState());
  Stop();
  if (remoteControlState.getleftMiniJoystickYDirection()=='U')
    forward(speed);
  if (remoteControlState.getleftMiniJoystickYDirection()=='D')
    backward(speed);
  if (remoteControlState.getRightMiniJoystickXDirection()=='R')
    right(speed);
  if (remoteControlState.getRightMiniJoystickXDirection()=='L')
    left(speed);     
}

void forward(int speed) {
  Serial.println("FORWARD");
    motor1.run(FORWARD);  //rotate the motor clockwise
    motor2.run(FORWARD);  //rotate the motor clockwise
    motor3.run(FORWARD);  //rotate the motor clockwise
    motor4.run(FORWARD);  //rotate the motor clockwise
   for (int speed = 110; speed <= 255; speed += 3) {
     motor1.setSpeed(speed); //Define maximum velocity
     motor2.setSpeed(speed); //Define maximum velocity
     motor3.setSpeed(speed); //Define maximum velocity
     motor4.setSpeed(speed); //Define maximum velocity
     delay(1);
   }
}

void backward(int speed) {
  Serial.println("BACKWARD");  
    motor1.run(BACKWARD);  //rotate the motor clockwise
    motor2.run(BACKWARD);  //rotate the motor clockwise
    motor3.run(BACKWARD);  //rotate the motor clockwise
    motor4.run(BACKWARD);  //rotate the motor clockwise
   for (int speed = 110; speed <= 255; speed += 3) {
     motor1.setSpeed(speed); //Define maximum velocity
     motor2.setSpeed(speed); //Define maximum velocity
     motor3.setSpeed(speed); //Define maximum velocity
     motor4.setSpeed(speed); //Define maximum velocity
     delay(1);
   }
}

void left(int speed) {
   Serial.println("LEFT");  
  motor1.setSpeed(speed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speed); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(speed); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right(int speed) {
   Serial.println("RIGHT");    
  motor1.setSpeed(speed); //Define maximum velocity
  motor1.run(FORWARD);  //rotate the motor clockwise
  motor2.setSpeed(speed); //Define maximum velocity
  motor2.run(FORWARD);  //rotate the motor clockwise
  motor3.setSpeed(speed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void Stop() {
     Serial.println("STOP");  
  motor1.setSpeed(0);  //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0);  //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0);  //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0);  //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
