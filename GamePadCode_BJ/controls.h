#include <Bounce2.h>
int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

int buttonPins[4] = {0, 1, 2, 3}; // holds the value of buttons
int buttonBuffer[4] = {0, 0}; // holds the state of each button

int joyStickPins[2] = {A1, A0}; // values for the joystick
int joyStickBuffer[2] = {0, 0}; // state for the joystick

int inputsTime = 200;

Metro inputsTimer = Metro(inputsTime); // print 5 times a second.


void initControls() {
  for ( int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(buttonBounce);
  }
}


void getControls() {
  for (int i = 0; i < 4; i++) {         // update the values of the buttons
    buttons[i].update();
    if (buttons[i].fell()) {
      buttonBuffer[i] = 1;
    }
    else {
      buttonBuffer[i] = 0;
    }

  }






  // read the joytstick potentiometers
  int xJoyValue = analogRead(joyStickPins[0]);
  int yJoyValue = analogRead(joyStickPins[1]);

  // give them a direction

  if (xJoyValue < 300) {
    joyStickBuffer[1] = 1;
  } else if (xJoyValue > 700) {
    joyStickBuffer[1] = -1;
  } else {
    joyStickBuffer[1] = 0;
  }

  if (yJoyValue < 300) {
    joyStickBuffer[0] = 1;
  } else if (yJoyValue > 700) {
    joyStickBuffer[0] = -1;
  } else {
    joyStickBuffer[0] = 0;
  }
}
