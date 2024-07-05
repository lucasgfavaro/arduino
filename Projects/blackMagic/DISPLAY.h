// Display.h
#ifndef DISPLAY_H
#define DISPLAY_H


#include "JOYSTICK.h"
#include "CHARACTERS.h"

class Display {
private:
  LiquidCrystal_I2C* lcd;
public:
  Display(LiquidCrystal_I2C* lcdPtr)
    : lcd(lcdPtr) {
    lcd->begin(16, 2);
    lcd->backlight();
    initializeCharacters();
  }

  void initializeCharacters() {
    // MAX 8 Characters from 0 to 7
    lcd->createChar(0, centered);
    lcd->createChar(1, up);
    lcd->createChar(2, down);
    lcd->createChar(3, buttonOff);
    lcd->createChar(4, buttonOn);
    lcd->createChar(5, toggleSwitchOff);
    lcd->createChar(6, toggleSwitchOn);
  }

  void joystick(MiniJoystick joystick) {
    unsigned int startingCell;

    if (joystick.getName().equals("LEFT")) {
      startingCell = 3;
    } else {
      startingCell = 9;
    }

    lcd->setCursor(startingCell, 0);
    switch (joystick.getYDirection()) {
      case 'U':
        lcd->write(byte(1));
        break;
      case 'D':
        lcd->write(byte(2));
        break;
      case 'C':
        lcd->write(byte(0));
        break;
    }
    lcd->print(joystick.getYPower());

    lcd->setCursor(startingCell, 1);
    switch (joystick.getXDirection()) {
      case 'R':
        lcd->print(">");
        break;
      case 'L':
        lcd->print("<");
        break;
      case 'C':
        lcd->write(byte(0));
        break;
    }
    lcd->print(joystick.getXPower());
  }

  void leftButtonOn() {
    lcd->setCursor(0, 0);
    lcd->write(byte(4));
  }

  void leftButtonOff() {
    lcd->setCursor(0, 0);
    lcd->write(byte(3));
  }

  void rightButtonOn() {
    lcd->setCursor(15, 0);
    lcd->write(byte(4));
  }

  void rightButtonOff() {
    lcd->setCursor(15, 0);
    lcd->write(byte(3));
  }

  void leftToggleSwitchOn() {
    lcd->setCursor(0, 1);
    lcd->write(byte(6));
  }

  void leftToggleSwitchOff() {
    lcd->setCursor(0, 1);
    lcd->write(byte(5));
  }

  void rightToggleSwitchOn() {
    lcd->setCursor(15, 1);
    lcd->write(byte(6));
  }

  void rightToggleSwitchOff() {
    lcd->setCursor(15, 1);
    lcd->write(byte(5));
  }

};

#endif