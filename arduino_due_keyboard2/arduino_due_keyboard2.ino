#include "Keyboard.h"

const int inputPin = 3;
bool currentState = HIGH;
bool beforeState = HIGH;

void setup() {
  SerialUSB.begin(115200);
  SerialUSB.println("Hello World");
  pinMode(inputPin,INPUT_PULLUP);
  //pinMode(ledPin, OUTPUT);
  //Keyboard.begin();
}

void loop() {
  currentState = digitalRead(inputPin);
  SerialUSB.println("This is loop");
  if ( currentState != beforeState ){
    if ( currentState == LOW){
      //digitalWrite(ledPin, HIGH);
      Serial.println("Push!");
      //Keyboard.press( 0x61 );
    } else {
      //digitalWrite(ledPin, LOW);
      Serial.println("Release!");
      //Keyboard.release( 0x61 );
    }
  beforeState = currentState;
  }
  delay(500);
}
