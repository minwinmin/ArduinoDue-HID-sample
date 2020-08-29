#include "Keyboard.h"

const int inputPin = 3;
bool currentState = HIGH;
bool beforeState = HIGH;

void setup() {
  SerialUSB.begin(115200);
  SerialUSB.println("Hello World");
  pinMode(inputPin,INPUT);
  //pinMode(ledPin, OUTPUT);
  Keyboard.begin();
}

void loop() {
  int currentState = digitalRead(inputPin);
  SerialUSB.println("This is loop");
  SerialUSB.println(currentState);
  if ( currentState == 1){
      //digitalWrite(ledPin, HIGH);
      SerialUSB.println("Push!");
      Keyboard.press( 0x61 );
  } else {
      //digitalWrite(ledPin, LOW);
      SerialUSB.println("Release!");
      Keyboard.release( 0x61 );
  }

  delay(500);
}