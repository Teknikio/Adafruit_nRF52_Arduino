#include <Bluebird_Teknikio.h>

uint8_t value_red;
uint8_t value_blue;
uint8_t value_green;


void setup() {
  // put your setup code here, to run once:
  value_red = 0;
  value_blue = 0;
  value_green = 0;
  
  Serial.begin(9600);
  delay(4000);
  Serial.println("Bluebird Neopixel test: START");
  bluebird.begin();

  bluebird.setPixelColor(0,0,0,0 ); // Set the LED off
  delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  bluebird.senseColor(value_red,value_green,value_blue);


  Serial.print("Red : ");
  Serial.println(value_red); 
  Serial.print("Green : ");
  Serial.println(value_green);
  Serial.print("Blue : ");
  Serial.println(value_blue);
  delay(100);
}
