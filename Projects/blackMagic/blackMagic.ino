#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "BLACKMAGIC_RC_STATE.h"
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
MiniJoystick rightMiniJoystick(rightJoystickPinX, rightJoystickPinY, rightJoystickButton);
MiniJoystick leftMiniJoystick(leftJoystickPinX, leftJoystickPinY, leftJoystickButton);
Button rightButton(rightButtonPin);
Button leftButton(leftButtonPin);
Button rightToggleSwitch(rightButtonPin);
Button leftToggleSwitch(leftButtonPin);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Display* display;
BlackMagicRemoteControlState remoteControlState;

void setup() {
  Serial.begin(nanoSerialBaudRate);
  initializeBluetooth(HCO5SerialBaudRate);
  display = new Display(&lcd);
}

void loop() {
  remoteControlState.setState(leftMiniJoystick.getState(), leftButton.getState(), leftToggleSwitch.getState(), rightMiniJoystick.getState(), rightButton.getState(), rightToggleSwitch.getState());
  display->updateDisplay(&leftMiniJoystick, &leftButton, &leftToggleSwitch, &rightMiniJoystick, &rightButton, &rightToggleSwitch);
  sendRemoteCommand(remoteControlState.getState());
  delay(10);
}

void sendRemoteCommand(String state) {
  String command = state + "\n";
  Serial.print(command);
  HCO5Serial.write(command.c_str());
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
