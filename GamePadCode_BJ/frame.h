
#include <Metro.h> // This adds the Metro library to your sketch

int timeLength = 1000;
int frameValue = 0;

Metro timer1 = Metro(timeLength); // A prototype for a Metro timer

void checkFrame() {

  if (timer1.check()) {
    Serial.println(frameValue);
  }

  frameValue++;
}
