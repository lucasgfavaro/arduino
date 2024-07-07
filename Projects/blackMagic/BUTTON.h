// Button.h
#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    int pin;
    int state;

  public:
    // Constructor
    Button(int buttonPin) {      
      pin = buttonPin;
      pinMode(buttonPin, INPUT_PULLUP);
    }

    char getState() {
      state = digitalRead(pin);
      if (state==1)
        return '0';
      return '1';
    }

    boolean isActive(){
      if (state==0)
        return true;
      return false;
    }
};

#endif