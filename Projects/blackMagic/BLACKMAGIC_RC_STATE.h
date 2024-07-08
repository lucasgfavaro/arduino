// BlackMagic_RC.h
#ifndef BLACKMAGIC_RC_STATE_H
#define BLACKMAGIC_RC_STATE_H

class BlackMagicRemoteControlState {
private:
  char leftMiniJoystickXDirection;
  String leftMiniJoystickXPower;
  char leftMiniJoystickYDirection;
  String leftMiniJoystickYPower;
  char leftMiniJoystickButtonOn;
  char leftButtonOn;
  char leftToggleButtonOn;
  char rightMiniJoystickXDirection;
  String rightMiniJoystickXPower;
  char rightMiniJoystickYDirection;
  String rightMiniJoystickYPower;
  char rightMiniJoystickButtonOn;
  char rightButtonOn;
  char rightToggleButtonOn;

public:
  BlackMagicRemoteControl() {
  }

  void setStateFromCommand(String state) {
    setState(state.substring(0, 9), state.charAt(9), state.charAt(10), state.substring(11, 20), state.charAt(20), state.charAt(21));
  }

  void setState(String leftMiniJoystickState, char leftButtonState, char leftToggleSwitchState, String rightMiniJoystickState, char rightButtonState, char rightToggleSwitchState) {

    leftMiniJoystickXDirection = leftMiniJoystickState.charAt(0);
    leftMiniJoystickXPower = leftMiniJoystickState.substring(1, 4);
    leftMiniJoystickYDirection = leftMiniJoystickState.charAt(4);
    leftMiniJoystickYPower = leftMiniJoystickState.substring(5, 8);
    leftMiniJoystickButtonOn = leftMiniJoystickState.charAt(8);
    leftButtonOn = leftButtonState;
    leftToggleButtonOn = leftToggleSwitchState;

    rightMiniJoystickXDirection = rightMiniJoystickState.charAt(0);
    rightMiniJoystickXPower = rightMiniJoystickState.substring(1, 4);
    rightMiniJoystickYDirection = rightMiniJoystickState.charAt(4);
    rightMiniJoystickYPower = rightMiniJoystickState.substring(5, 8);
    rightMiniJoystickButtonOn = rightMiniJoystickState.charAt(8);
    rightButtonOn = rightButtonState;
    rightToggleButtonOn = rightToggleSwitchState;
  }

  String getState() {
    return String(leftMiniJoystickXDirection) + String(leftMiniJoystickXPower) + String(leftMiniJoystickYDirection) + String(leftMiniJoystickYPower)
           + leftMiniJoystickButtonOn + leftButtonOn + leftToggleButtonOn
           + String(rightMiniJoystickXDirection) + String(rightMiniJoystickXPower) + String(rightMiniJoystickYDirection) + String(rightMiniJoystickYPower)
           + rightMiniJoystickButtonOn + rightButtonOn + rightToggleButtonOn;
  }

  char getLeftMiniJoystickXDirection() {
    return leftMiniJoystickXDirection;
  }

  String getLeftMiniJoystickXPower() {
    return leftMiniJoystickXPower;
  };

  char getleftMiniJoystickYDirection() {
    return leftMiniJoystickYDirection;
  }

  String getLeftMiniJoystickYPower() {
    return leftMiniJoystickYPower;
  };

  boolean getLeftMiniJoystickButtonOn() {
    if (leftMiniJoystickButtonOn == 1)
      return true;
    return false;
  }

  boolean getLeftButtonOn() {
    if (leftButtonOn == 1)
      return true;
    return false;
  }

  boolean getLeftToggleButtonOn() {
    if (leftToggleButtonOn == 1)
      return true;
    return false;
  }

  char getRightMiniJoystickXDirection() {
    return rightMiniJoystickXDirection;
  }

  String getRightMiniJoystickXPower() {
    return rightMiniJoystickXPower;
  };

  char getRightMiniJoystickYDirection() {
    return rightMiniJoystickYDirection;
  }

  String getRightMiniJoystickYPower() {
    return rightMiniJoystickYPower;
  };

  boolean getRightMiniJoystickButtonOn() {
    if (rightMiniJoystickButtonOn == 1)
      return true;
    return false;
  }

  boolean getRightButtonOn() {
    if (rightButtonOn == 1)
      return true;
    return false;
  }

  boolean getRightToggleButtonOn() {
    if (rightToggleButtonOn == 1)
      return true;
    return false;
  }
};

#endif
