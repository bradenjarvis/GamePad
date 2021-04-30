// Earth Escape
// Braden Jarvis || Mar 2021
// CRT 360 Advanced Prototyping || Gamepad

int curMode = -1; //intro screen start

#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "interaction.h"
#include "status.h"
#include "hero.h"
#include "modes.h"


void setup() {
  
  initControls();
  initNeighbors();
  initScreen();
}


void loop() {

  getControls();
  runMode();
  checkFrame();


}
