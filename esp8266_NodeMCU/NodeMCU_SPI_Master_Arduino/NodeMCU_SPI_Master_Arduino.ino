#include<SPI.h>

uint8_t buff[3]={1,2,3};
void setup() {
  //Serial.begin(9600); //begin serial with 9600 baud
  pinMode(0, OUTPUT);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.begin();  //begin SPI
}

void loop() {
  for(int i=0; i<sizeof buff; i++){  // transfer buff data per second
  digitalWrite(0,1);
  SPI.transfer(buff[i]);
  delay(50);
  digitalWrite(0,0);
  delay(50);
  }  
}
