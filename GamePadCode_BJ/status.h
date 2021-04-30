
boolean curStatus = false;

void statusBar(int statusX, int statusY, int statusW, int statusH) {

  if (curStatus == false) {
    tft.drawRect(statusX, statusY, statusW, statusH, 0xFFFFFF);
    tft.fillRect(statusX + 1, statusY + 1, statusW - 1, statusH - 1, 0x0000FF);
    tft.updateScreen();
  }

  curStatus = true;
}
