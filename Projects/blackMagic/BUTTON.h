// Button.h
#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    String name;
    int pin;
    int status;

  public:
    // Constructor
    Button(String buttonName, int buttonPin) {
      name = buttonName;
      pin = buttonPin;
      pinMode(buttonPin, INPUT_PULLUP);
    }

    void refreshStatus() {
      status = digitalRead(pin);
    }

    String toString() {
      return name + " Status: " + status;
    }

    boolean isActive(){
      if (status==0)
        return true;
      return false;
    }
};

#endif