#include <Bluebird_Teknikio.h>


void setup() {
 bluebird.begin();
}

void loop() {
  // Can be used in RGB mode
  bluebird.setPixelColor(0,255,0,0 ); // Red
  // Define the color by a position on the color wheel
  // bluebird.setPixelColor(0, bluebird.colorWheel(25));
  delay(500);
  bluebird.setPixelColor(0,0,255,0 ); // Green
  // bluebird.setPixelColor(0, bluebird.colorWheel(125));
  delay(500);
  bluebird.setPixelColor(0,0,0,255 ); // Blue
  delay(500);
  
  Serial.println("Bluebird Neopixel test: End of Sequence");
}
