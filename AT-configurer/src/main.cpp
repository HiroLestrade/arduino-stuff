#include <Arduino.h>
#include <SoftwareSerial.h>
//*******************************************************************************************
#define BAUD_RATE 38400
#define EN 11
#define RX 12
#define TX 13
SoftwareSerial bt(RX,TX);

//*******************************************************************************************
String SerialInput(String msg){
  Serial.println(msg);
  while(!Serial.available()){}
  return Serial.readString();
}

//*******************************************************************************************
void setup() {
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
  Serial.begin(9600);
  bt.begin(BAUD_RATE);
}

void loop() {
  if(Serial.available()){
    String msg = Serial.readString();
    bt.println(msg);
  }
  if(bt.available()){
    String msg = bt.readString();
    Serial.println(msg);
  }
}
