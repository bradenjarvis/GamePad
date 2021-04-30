
#include "introscreen5_MASK.h"
#include "introscreen5_PIX.h"

#define screenW 320
#define screenH 240


boolean initIntro = false;
boolean initLevel1 = false;


void introScreen() {
  if (!initIntro) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, introscreen5_PIX[0], introscreen5_MASK[0], screenW, screenH);
    tft.updateScreen();
  }
  initIntro = true;
  if (buttonBuffer[0] == 1) {
    curMode = 0;
  }
}

void firstLevel() {
  initIntro = false;
  if (initLevel1 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    tft.updateScreen();
    initLevel1 = true;
    //enemyStatus = true;
  }
  drawLevel(0);
  //statusBar(healthX, healthY, healthW, healthH);
  drawHero();
  if (interaction[curMode][curTile] == 0x01 && buttonBuffer[0] == 1) {
    curMode = 1;
    initLevel1 = false;
  }
}



void runMode() {

  switch (curMode) {


    case -1: introScreen(); break;
    case 0: firstLevel(); break;



  }
}
