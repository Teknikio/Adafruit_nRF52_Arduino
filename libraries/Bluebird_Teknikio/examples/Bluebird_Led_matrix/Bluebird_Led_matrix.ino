#include <Bluebird_Teknikio.h>


uint8_t Tpattern[ROW_SIZE][COLUMN_SIZE] = {
                          {1,1,1,1,1,1},
                          {1,1,1,1,1,1},
                          {0,0,1,1,0,0},
                          {0,0,1,1,0,0},
                          {0,0,1,1,0,0}
                        };
                        
uint8_t Epattern[ROW_SIZE][COLUMN_SIZE] = {
                          {1,1,1,1,1,1},
                          {1,1,0,0,0,0},
                          {1,1,1,1,1,1},
                          {1,1,0,0,0,0},
                          {1,1,1,1,1,1}
                        };
uint8_t Kpattern[ROW_SIZE][COLUMN_SIZE] = {
                          {1,1,0,0,1,1},
                          {1,1,0,1,1,0},
                          {1,1,1,1,0,0},
                          {1,1,0,1,1,0},
                          {1,1,0,0,1,1}
                        };
uint8_t Npattern[ROW_SIZE][COLUMN_SIZE] = {
                          {1,1,0,0,1,1},
                          {1,1,1,0,1,1},
                          {1,1,1,1,1,1},
                          {1,1,0,1,1,1},
                          {1,1,0,0,1,1}
                        };
uint8_t Ipattern[ROW_SIZE][COLUMN_SIZE] = {
                          {1,1,1,1,1,1},
                          {0,0,1,1,0,0},
                          {0,0,1,1,0,0},
                          {0,0,1,1,0,0},
                          {1,1,1,1,1,1}
                        };
uint8_t Opattern[ROW_SIZE][COLUMN_SIZE] = {
                          {1,1,1,1,1,1},
                          {1,1,1,1,1,1},
                          {1,1,0,0,1,1},
                          {1,1,1,1,1,1},
                          {1,1,1,1,1,1}
                        };

                        
int time_delay = 400;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(400);
  bluebird.begin();
  Serial.print("Test");
  bluebird.setLedMatrix(1,1);
  delay(5000);
  Serial.println("Bluebird full test: START");
  bluebird.changepattern(Tpattern);
  //bluebird.ledpattern = Tpattern;
}

void loop() {
  
  // put your main code here, to run repeatedly:
  //bluebird.ledpattern = Tpattern;
  bluebird.changepattern(Tpattern);
  delay(time_delay);                      
  bluebird.changepattern(Epattern);
  delay(time_delay);                      
  bluebird.changepattern(Kpattern);
  delay(time_delay);                      
  bluebird.changepattern(Npattern);
  delay(time_delay);                      
  bluebird.changepattern(Ipattern);
  delay(time_delay);      
  bluebird.changepattern(Kpattern);
  delay(time_delay);                      
  bluebird.changepattern(Ipattern);
  delay(time_delay);      
  bluebird.changepattern(Opattern);
  delay(time_delay);                                                      
  //bluebird.ledpattern = Tpattern;             
  Serial.println("Fin de TEKNIKIO");
  
  


}
