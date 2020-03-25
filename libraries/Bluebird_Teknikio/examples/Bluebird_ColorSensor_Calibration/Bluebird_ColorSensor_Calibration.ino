#include <Bluebird_Teknikio.h>

bool calibration = false;
bool tmp_status = true;
int incomingByte=0;
uint8_t value_red = 0;
uint8_t value_blue = 0;
uint8_t value_green = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(4000);
  Serial.println("Bluebird Neopixel test: START");
  bluebird.begin();
  while(Serial.available()==0)
  {
    
    if( tmp_status == true)
    {
      tmp_status = false;
      bluebird.setPixelColor(0,255,0,0 ); // Red
    }
    else
    {
      tmp_status = true;
      bluebird.setPixelColor(0,0,0,255 ); // Blue
    }
    delay(100);
  }
  incomingByte = Serial.read();
  bluebird.setPixelColor(0,0,255,0 ); // Green
  delay(500);
}

void loop() { 

  if( calibration == false)
  {
    Serial.println("Thanks to present a white sheet in front of the sensors");
    while (Serial.available() == 0) {
     delay(100);
     if( tmp_status == true)
    {
      tmp_status = false;
      bluebird.setPixelColor(0,255,255,0 ); // Red
    }
    else
    {
      tmp_status = true;
      bluebird.setPixelColor(0,0,255,255 ); // Blue
    }
    delay(100);
     }
    // read the incoming byte:
    incomingByte = Serial.read();

    bluebird.calibratesenseColor(BLUEBIRD_MAX_CALIB,bluebird.max_red,bluebird.max_green,bluebird.max_blue);

    Serial.print("Red : ");
    Serial.print(bluebird.max_red); 
    Serial.println(" ");
    Serial.print("Green : ");
    Serial.print(bluebird.max_green);
    Serial.println(" ");
    Serial.print("Blue : ");
    Serial.print(bluebird.max_blue);
    Serial.println(" "); 
    Serial.println("Thanks to present a black sheet in front of the sensors");
    while (Serial.available() == 0) {
     delay(100);
     if( tmp_status == true)
    {
      tmp_status = false;
      bluebird.setPixelColor(0,255,255,0 ); // Red
    }
    else
    {
      tmp_status = true;
      bluebird.setPixelColor(0,0,255,255 ); // Blue
    }
    delay(100);
     }
    // read the incoming byte:
    incomingByte = Serial.read();

    bluebird.calibratesenseColor(BLUEBIRD_MIN_CALIB,bluebird.min_red,bluebird.min_green,bluebird.min_blue);

    Serial.print("Red : ");
    Serial.print(bluebird.min_red); 
    Serial.println(" ");
    Serial.print("Green : ");
    Serial.print(bluebird.min_green);
    Serial.println(" ");
    Serial.print("Blue : ");
    Serial.print(bluebird.min_blue);
    Serial.println(" "); 

    Serial.println("End of the calibration"); 
    calibration = true;
  }
  else{
    
    bluebird.senseColor(value_red,value_green,value_blue);

    Serial.print("Red : ");
    Serial.print(value_red); 
    Serial.println(" %");
    Serial.print("Green : ");
    Serial.print(value_green);
    Serial.println(" %");
    Serial.print("Blue : ");
    Serial.print(value_blue);
    Serial.println(" %"); 
    delay(100);
  }
  
}
