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
    //printDisplayLayout();
  }

  void initializeCharacters() {
    lcd->createChar(0, centered);
    lcd->createChar(1, rightArrow);
    lcd->createChar(2, leftArrow);
    lcd->createChar(3, upArrow);
    lcd->createChar(4, downArrow);
    lcd->createChar(5, buttonOff);
    lcd->createChar(6, buttonOn);
    // lcd->createChar(7, toggleSwitchOff);
    // lcd->createChar(8, toggleSwitchOn);
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
        lcd->write(byte(3));
        break;
      case 'D':
        lcd->write(byte(4));
        break;
      case 'C':
        lcd->write(byte(0));
        break;
    }
    lcd->print(joystick.getYPower());

    lcd->setCursor(startingCell, 1);
    switch (joystick.getXDirection()) {
      case 'R':
        lcd->write(byte(1));
        break;
      case 'L':
        lcd->write(byte(2));
        break;
      case 'C':
        lcd->write(byte(0));
        break;
    }
    lcd->print(joystick.getXPower());
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

  // void leftToggleSwitchOn() {
  //   lcd->setCursor(0, 1);
  //   lcd->write(byte(8));
  // }

  // void leftToggleSwitchOff() {
  //   lcd->setCursor(0, 1);
  //   lcd->write(byte(7));
  // }

  // void rightToggleSwitchOn() {
  //   lcd->setCursor(15, 1);
  //   lcd->write(byte(8));
  // }

  // void rightToggleSwitchOff() {
  //   lcd->setCursor(15, 1);
  //   lcd->write(byte(7));
  // }

  // void printDisplayLayout() {
  //   lcd->clear();

  //   leftButtonOff();
  //   rightButtonOff();
  //   leftToggleSwitchOff();
  //   rightToggleSwitchOff();
  //   joystick('L', 'R', 255, 'U', 255, true);
  //   joystick('R', 'L', 255, 'D', 255, false);

  //   delay(2000);

  //   leftButtonOn();
  //   rightButtonOn();
  //   leftToggleSwitchOn();
  //   rightToggleSwitchOn();
  //   joystick('L', 'L', 255, 'D', 255, false);
  //   joystick('R', 'R', 255, 'U', 255, true);

  //   delay(2000);
  // }
};

#endif