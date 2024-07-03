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
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include "JOYSTICK.h"
#include "BUTTON.h"

const int nanoSerialBaudRate = 9600;
const unsigned long HCO5SerialBaudRate = 38400;

const int rightJoystickPinX = A0;
const int rightJoystickPinY = A1;
const int rightJoystickButton = 12;
const int leftJoystickPinX = A2;
const int leftJoystickPinY = A3;
const int leftJoystickButton = 11;
const int leftButtonPin = 10;
const int rightButtonPin = 4;
const int blueToothTX = 2;
const int blueToothRX = 3;

SoftwareSerial HCO5Serial(blueToothTX, blueToothRX);  // RX, TX
Joystick rightJoystick("RIGHT JOYSTICK", rightJoystickPinX, rightJoystickPinY, rightJoystickButton);
Joystick leftJoystick("LEFT JOYSTICK", leftJoystickPinX, leftJoystickPinY, leftJoystickButton);
Button rightButton("RIGHT BUTTON", rightButtonPin);
Button leftButton("LEFT BUTTON", leftButtonPin);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(nanoSerialBaudRate);
  HCO5Serial.begin(HCO5SerialBaudRate);
  initializeDisplay();
  //initializeBluetooth(38400);
}

void loop() {

  rightJoystick.refreshStatus();
  leftJoystick.refreshStatus();
  rightButton.refreshStatus();
  leftButton.refreshStatus();

  if (rightJoystick.getXPositionAndPower().indexOf("R") >= 0){
    HCO5Serial.write("R");
  } 
  else if (rightJoystick.getXPositionAndPower().indexOf("L")>= 0){
    HCO5Serial.write("L");
  }
  else if (leftJoystick.getYPositionAndPower().indexOf("U")>= 0){
    HCO5Serial.write("F");
  }
  else if (leftJoystick.getYPositionAndPower().indexOf("D")>= 0){
    HCO5Serial.write("B");
  } else {
    HCO5Serial.write("S");
  }
  displayUpdate();

  printJoystickStatus();
}

void displayUpdate(){
    lcd.clear();
    
    if (leftButton.isActive()){
      lcd.setCursor(0, 0);
      lcd.print("BX");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("B");
    }

    if (rightButton.isActive()){
      lcd.setCursor(14, 0);
      lcd.print("BX");
    } else {
      lcd.setCursor(14, 0);
      lcd.print("B");
    }

    // lcd.setCursor(0, 1);
    // lcd.print("SX");
    // lcd.setCursor(14, 1);
    // lcd.print("SX");

  if (rightJoystick.getXPositionAndPower().indexOf("R") >= 0){
     lcd.setCursor(5, 0);
     lcd.print("RIGHT");
  } 
  else if (rightJoystick.getXPositionAndPower().indexOf("L")>= 0){
     lcd.setCursor(5, 0);
     lcd.print("LEFT");
  }
  else if (leftJoystick.getYPositionAndPower().indexOf("U")>= 0){
     lcd.setCursor(4, 0);
     lcd.print("FORWARD");
  }
  else if (leftJoystick.getYPositionAndPower().indexOf("D")>= 0){
     lcd.setCursor(4, 0);
     lcd.print("BACKWARD");
  }

  lcd.setCursor(4, 1);
  lcd.print("PWR:");

}

int calcultaPower(){
  int greatest;

  greatest = a; // Assume a is the greatest to start with

  if (b > greatest) {
    greatest = b;
  }
  if (c > greatest) {
    greatest = c;
  }
  if (d > greatest) {
    greatest = d;
  }

}

void initializeDisplay(){
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Systems Check...");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Systems Ok");
  delay(2000);
  lcd.clear();
  lcd.print("Welcome!");
  delay(2000);
  lcd.clear();
}



void initializeBluetooth(int baud){
  Serial.println(baud);
  HCO5Serial.begin(baud);

  // Iniciar conexión con el esclavo (usar la dirección del esclavo obtenida anteriormente)
  //BTSerial.print("AT+BIND=98DA:50:02E823");  // Slave MAC
  //delay(1000);
  //BTSerial.print("AT+CMODE=0");
  //delay(1000);
  //BTSerial.print("AT+LINK=98DA:50:02E823");
}

void printJoystickStatus() {
  Serial.print(rightJoystick.toString() + " " + leftJoystick.toString() + " " + rightButton.toString() + " " + leftButton.toString() + "\r\n");
}

void sendCommand(char command) {
  Serial.println(command);
  HCO5Serial.write(command);
}
