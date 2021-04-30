#include "korvo_MASK.h"
#include "korvo_PIX.h"


#define tileW 16         // 16 Tiles Across
#define tileH 12         // 12 Tiles Down
#define tileSize 20      // Tile Width


float heroX = 100;
float heroY = 100;
float heroSpeed = 0.5;
int heroSize = 64;
int heroDir = 0;
int heroFrame = 0;
int heroTime = 250;

int healthX = 250;
int healthY = 15;
int healthW = 60;
int healthH = 8;

Metro heroFrameTimer = Metro(heroTime); // A prototype for a Metro timer


void drawHero() {

  float nextX = heroX + (float(joyStickBuffer[0]) * heroSpeed);
  float nextY = heroY + (float(joyStickBuffer[1]) * heroSpeed);

  if (checkMove(curMode, nextX, nextY, heroSize, heroSize) == true) {
    heroX = nextX;
    heroY = nextY;
  }

  if (joyStickBuffer[0] < 0 || joyStickBuffer[1] < 0 ) {
    heroDir = -1;
  } else if (joyStickBuffer[0] > 0 || joyStickBuffer[1] > 0) {
    heroDir = 1;
  } else {
    heroDir = 0;
  }


  if (heroFrameTimer.check()) {
    if (heroDir == 1) {
      heroFrame = 1 + (heroFrame + 1) % 3;
    }
    else if (heroDir == -1) {
      heroFrame = 7 + (heroFrame + 1) % 3;
    }
    else {
      heroFrame = 0;
    }
  }


  tft.setClipRect((heroX), (heroY), 64, 64);

  tft.drawRGBBitmap(heroX, heroY, korvo_PIX[heroFrame], korvo_MASK[heroFrame], heroSize, heroSize);

  

  tft.updateScreen();


}
