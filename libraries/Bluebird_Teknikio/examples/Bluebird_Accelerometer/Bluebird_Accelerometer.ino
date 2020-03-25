#include <Bluebird_Teknikio.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(4000);
  Serial.println("Bluebird Neopixel test: START");
  bluebird.begin();
  delay(50);
}

void loop() { 
  Serial.print("x = ");
  Serial.print(bluebird.rotationX());
  Serial.println(" dps");
  Serial.print("y = ");
  Serial.print(bluebird.rotationY());
  Serial.println(" dps");
  Serial.print("z = ");
  Serial.print(bluebird.rotationZ());
  Serial.println(" dps");
  Serial.print("x = ");
  Serial.print(bluebird.motionX());
  Serial.println(" mg");
  Serial.print("y = ");
  Serial.print(bluebird.motionY());
  Serial.println(" mg");
  Serial.print("z = ");
  Serial.print(bluebird.motionZ());
  Serial.println(" mg");
  delay(100);
  Serial.println("Bluebird Neopixel test: End of Sequence");
}
