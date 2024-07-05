// Display.h
#ifndef DISPLAY_H
#define DISPLAY_H


#include "CHARACTERS.h"

class Display {
private:
  LiquidCrystal_I2C* lcd; 
public:
  Display(LiquidCrystal_I2C* lcdPtr): lcd(lcdPtr) {
    lcd->begin(16, 2);
    lcd->backlight();
    //Serial.print("PASO1.2");
    initializeCharacters();
    printDisplayLayout();
  }

  // void welcomeMessage() {
  //   lcd->clear();
  //   lcd->setCursor(0, 0);
  //   lcd->rightToLeft();
  //   lcd->print("Welcome!");
  //   delay(2000);
  // }

  void initializeCharacters() {
    lcd->createChar(1, leftArrow);
    lcd->createChar(2, rightArrow);
    lcd->createChar(3, upArrow);
    lcd->createChar(4, downArrow);
    lcd->createChar(5, buttonOff);
    lcd->createChar(6, buttonOn);
    lcd->createChar(7, toggleSwitchOff);
    lcd->createChar(8, toggleSwitchOn);
    lcd->createChar(9, centered);
        lcd->createChar(10, leftArrow);
  }

  void leftButtonOn() {
    lcd->setCursor(0, 0);
    lcd->write(byte(6));
  }

  void leftButtonOff() {
    lcd->setCursor(0, 0);
    lcd->write(byte(5));
  }

  void rightButtonOn() {
    lcd->setCursor(15, 0);
    lcd->write(byte(6));
  }

  void rightButtonOff() {
    lcd->setCursor(15, 0);
    lcd->write(byte(5));
  }

  void leftToggleSwitchOn() {
    lcd->setCursor(0, 1);
    lcd->write(byte(8));
  }

  void leftToggleSwitchOff() {
    lcd->setCursor(0, 1);
    lcd->write(byte(7));
  }

  void rightToggleSwitchOn() {
    lcd->setCursor(15, 1);
    lcd->write(byte(8));
  }

  void rightToggleSwitchOff() {
    lcd->setCursor(15, 1);
    lcd->write(byte(7));
  }

  void joystick(char leftRight, char xDirection, long xPower, char yDirection, long yPower, boolean buttonOn) {
    unsigned int startingCell;

    switch (leftRight) {
      case 'L':
        startingCell = 3;
        break;
      case 'R':
        startingCell = 9;
        break;
    }

    lcd->setCursor(startingCell, 1);
    switch (xDirection) {
      case 'L':
        lcd->write(byte(10));
        lcd->print(xPower);
        break;
      case 'R':
        lcd->write(byte(2));
        lcd->print(xPower);
        break;
      case 'C':
        lcd->write(byte(9));
        lcd->print(xPower);
        break;
    }

    lcd->setCursor(startingCell, 0);
    switch (yDirection) {
      case 'U':
        lcd->write(byte(3));
        lcd->print(yPower);
        break;
      case 'D':
        lcd->write(byte(4));
        lcd->print(yPower);
        break;
      case 'C':
        lcd->write(byte(9));
        lcd->print(yPower);
        break;
    }
  }

  void printDisplayLayout() {
    lcd->clear();

    leftButtonOff();
    rightButtonOff();
    leftToggleSwitchOff();
    rightToggleSwitchOff();
    joystick('L', 'R', 255, 'U', 255, true);
    joystick('R', 'L', 255, 'D', 255, false);

    delay(1000);

    leftButtonOn();
    rightButtonOn();
    leftToggleSwitchOn();
    rightToggleSwitchOn();
    joystick('L', 'L', 255, 'D', 255, false);
    joystick('R', 'R', 255, 'U', 255, true);

    delay(1000);
  }
};

#endif