#include <Arduino.h>
#include <SoftwareSerial.h>

#define BAUD_RATE 38400

SoftwareSerial bt(12,13);

String SerialInput(String msg){
  Serial.println(msg);
  while(!Serial.available()){}
  return Serial.readString();
}

void setup() {
  Serial.begin(9600);
  bt.begin(BAUD_RATE);
}

void loop() {
  String msg = SerialInput("Texto: ");
  Serial.println(msg);
}
