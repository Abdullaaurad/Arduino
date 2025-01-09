
#include "Arduino.h"

void displayBinary(int num){
    for (int i = 2; i <= 7; i++){
        if (num & (1 << (i - 2))){
            digitalWrite(i, HIGH);
        }
        else{
            digitalWrite(i, LOW);
        }
    }
}

void setup(){
    for (int i = 2; i <= 7; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop(){
    for (int i = 1; i <= 32; i++){
        displayBinary(i);

        delay(1000);
    }
}
