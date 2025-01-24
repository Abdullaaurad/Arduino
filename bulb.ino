<<<<<<< HEAD
#include "Arduino.h"

void setup(){
    pinMode(13,OUTPUT);
}

void loop() {
    digitalWrite(13, HIGH);
    delay(100);          
    digitalWrite(13, LOW);   
    delay(100);
=======
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  delay(1000);
  digitalWrite(2,LOW);
  delay(1000);
>>>>>>> 57222f0366f680798ec4c945180449dfa62bb8d7
}
