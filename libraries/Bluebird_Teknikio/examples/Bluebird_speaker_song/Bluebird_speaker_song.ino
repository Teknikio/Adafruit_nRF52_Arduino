#include <Bluebird_Teknikio.h>

uint16_t measure = 0;
int melody[] = {
  NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_DS6,  NOTE_E6, NOTE_B5, NOTE_D6, NOTE_C6, NOTE_A5
}; //fur elise
int tempo[] = {
  12, 12, 12, 12, 12, 10, 12, 12, 6
};
uint8_t numberOfNotes = sizeof(melody)/sizeof(int);

void setup() {
  // put your setup code here, to run once:
  bluebird.begin();
  delay(50);
}
void loop() {
  // put your main code here, to run repeatedly:
 for (int n=0; n<numberOfNotes; n++) {
    int noteDuration = 1000 / tempo[n];
    bluebird.playTone(melody[n], noteDuration);
    delay(0.3*noteDuration);
  }
 
}
