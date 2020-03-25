#include <Bluebird_Teknikio.h>

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.println("Bluebird Neopixel test: START");
 bluebird.begin();
 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  bluebird.setPixelColor(0,255,0,0 ); // Red
  bluebird.playTone(1000, 100);
  Serial.print("x = ");
  Serial.print(bluebird.rotationX());
  Serial.println(" dps");
  Serial.print("x = ");
  Serial.print(bluebird.motionX());
  Serial.println(" mg");
  delay(500);
  bluebird.setPixelColor(0,0,255,0 ); // Green
  bluebird.playTone(2000, 100);
  Serial.print("y = ");
  Serial.print(bluebird.rotationY());
  Serial.println(" dps");
  Serial.print("y = ");
  Serial.print(bluebird.motionY());
  Serial.println(" mg");
  delay(500);
  bluebird.setPixelColor(0,0,0,255 ); // Blue
  bluebird.playTone(3000, 100);
  Serial.print("z = ");
  Serial.print(bluebird.rotationZ());
  Serial.println(" dps");
  Serial.print("z = ");
  Serial.print(bluebird.motionZ());
  Serial.println(" mg");
  delay(500);
  bluebird.setPixelColor(0,255,255,0 ); // Blue
  Serial.print("t = ");
  Serial.print(bluebird.getTemperature());
  Serial.println(" °C");
  Serial.print("Light = ");
  Serial.print(bluebird.lightSensor());
  Serial.println(" ");
  delay(500);
  Serial.println("Bluebird Neopixel test: End of Sequence");
}