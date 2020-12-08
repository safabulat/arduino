#define red 10
#define green 9
#define blue 11
int tdelay = 1000;
int brightness;
int fadeAmount = 5;
void setup()
{
  //******************************INIT LEDS************************//
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
 /*analogWrite(red, 255);
 analogWrite(green, 255);
 analogWrite(blue, 255);
 delay(500);*/
  //**********************************TEST************************//
  digitalWrite(red,LOW);    //off
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
  delay(1000);
  digitalWrite(red,LOW);    //blue
  digitalWrite(green,HIGH);
  digitalWrite(blue,HIGH);
  delay(3000);
  digitalWrite(red,HIGH);    //red
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
  delay(3000);
  digitalWrite(red,LOW);    //green
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  delay(3000);
  digitalWrite(red,HIGH);   //all
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  delay(10000);
  //**********************************TEST END************************//
}
 
void loop()
{ 
  digitalWrite(red|green,HIGH); //purple 
  digitalWrite(blue,HIGH);
  delay(3000);
  digitalWrite(red,HIGH); //Cyan
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
  delay(3000);
  //digitalWrite(green,HIGH); //yellow
  digitalWrite(blue,LOW);
  //digitalWrite(red,LOW);
  delay(3000);
  analogWrite(red,255);
  analogWrite(green,150);
  analogWrite(blue,55);
  delay(5000);
  
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(blue,LOW);
  delay(2000);
  
  digitalWrite(red,LOW);
  delay(1000);
  digitalWrite(green,LOW);
  delay(1000);
  digitalWrite(blue,HIGH);
  delay(2000);

  for (int i = 0, j = 255; i <= 255, j >= 0; i++, j--) {
    analogWrite(red,i);
    analogWrite(green,i);
    analogWrite(blue,j);
    delay(50);
  } 
  delay(500);
  for (int i = 255, j = 0; i >= 0, j <= 255; i--,j++) {
    
    analogWrite(red,i);
    analogWrite(green,i);
    analogWrite(blue,j);
    delay(50);
  }
  delay(2000);

  for (int i = 0; i <= 255; i++) {
    analogWrite(red,i);
    delay(10);
  }
   for (int i = 255; i >= 0; i--) {
    analogWrite(red,i);
    delay(10);
  }
   for (int i = 0; i <= 255; i++) {
    analogWrite(green,i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(green,i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(blue,i);
    delay(10);
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(blue,i);
    delay(10);
   } 
  delay(2000);
}
