#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DISPLAY.h"
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

MiniJoystick rightMiniJoystick("RIGHT", rightJoystickPinX, rightJoystickPinY, rightJoystickButton);
MiniJoystick leftMiniJoystick("LEFT", leftJoystickPinX, leftJoystickPinY, leftJoystickButton);
Button rightButton("RIGHT BUTTON", rightButtonPin);
Button leftButton("LEFT BUTTON", leftButtonPin);
Button rightToggleSwitch("RIGHT SWITCH", rightButtonPin);
Button leftToggleSwitch("LEFT SWITCH", leftButtonPin);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Display* display;

void setup() {
  Serial.begin(nanoSerialBaudRate);
  initializeBluetooth(HCO5SerialBaudRate);
  display = new Display(&lcd);
}

void loop() {
  refreshJoystickComponents();
  sendRemoteCommand();
  updateDisplay();
  debugJoystickStatus();
}

void refreshJoystickComponents() {
  rightMiniJoystick.refreshStatus();
  leftMiniJoystick.refreshStatus();
  rightButton.refreshStatus();
  leftButton.refreshStatus();
}

void updateDisplay() {
  lcd.clear();

  if (leftButton.isActive()) {
    display->leftButtonOn();
  } else {
    display->leftButtonOff();
  }

  if (rightButton.isActive()) {
    display->rightButtonOn();
  } else {
    display->rightButtonOff();
  }

  if (leftToggleSwitch.isActive()) {
    display->leftToggleSwitchOn();
  } else {
    display->leftToggleSwitchOff();
  }

  if (rightToggleSwitch.isActive()) {
    display->rightToggleSwitchOn();
  } else {
    display->rightToggleSwitchOff();
  }

  display->joystick(leftMiniJoystick);
  display->joystick(rightMiniJoystick);
}

void initializeBluetooth(unsigned long baud) {
  Serial.println(baud);
  HCO5Serial.begin(baud);

  // Iniciar conexión con el esclavo (usar la dirección del esclavo obtenida anteriormente)
  //BTSerial.print("AT+BIND=98DA:50:02E823");  // Slave MAC
  //delay(1000);
  //BTSerial.print("AT+CMODE=0");
  //delay(1000);
  //BTSerial.print("AT+LINK=98DA:50:02E823");
}

void debugJoystickStatus() {
  Serial.print(leftMiniJoystick.toString() + "  |  " + rightMiniJoystick.toString() + "\r\n");
}

void sendRemoteCommand() {
  // if (rightMiniJoystick.getXPositionAndPower().indexOf("R") >= 0){
  //   HCO5Serial.write("R");
  // }
  // else if (rightMiniJoystick.getXPositionAndPower().indexOf("L")>= 0){
  //   HCO5Serial.write("L");
  // }
  // else if (leftMiniJoystick.getYPositionAndPower().indexOf("U")>= 0){
  //   HCO5Serial.write("F");
  // }
  // else if (leftMiniJoystick.getYPositionAndPower().indexOf("D")>= 0){
  //   HCO5Serial.write("B");
  // } else {
  //   HCO5Serial.write("S");
  // }
}
