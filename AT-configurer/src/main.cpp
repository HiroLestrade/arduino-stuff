#include <Arduino.h>
#include <SoftwareSerial.h>
//*******************************************************************************************
#define DEFAULT_BAUD_RATE 38400
#define BAUD_RATE 9600
#define EN 8
#define RX 12
#define TX 13
SoftwareSerial bt(RX,TX);
bool operation = false;

//*******************************************************************************************
void configurationMode(){
  bt.end();
  bt.begin(DEFAULT_BAUD_RATE);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
}

void operationMode(){
  bt.end();
  bt.begin(BAUD_RATE);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
}

void SerialCommunication(){
  if(Serial.available()){
    String msg = Serial.readString();
    bt.println(msg);
  }
  if(bt.available()){
    String msg = bt.readString();
    Serial.println(msg);
  }
}

String SerialInput(String msg){
  Serial.println(msg);
  while(!Serial.available());
  return Serial.readString();
}

void sendCommand(String command){
  bt.println(command);
  while(!bt.available());
  Serial.println(bt.readString());
}

void printInfo(){
  sendCommand("AT+NAME?");
  sendCommand("AT+PSWD?");
  sendCommand("AT+ADDR?");
  sendCommand("AT+UART?");
  sendCommand("AT+ROLE?");
  sendCommand("AT+CMODE?");
  sendCommand("AT+BIND?");
}

void bluetoothConfigurerCLI(){
  String name, pswd, baud, stop, parity, role, cmode, bind;

  Serial.println("********** Bluetooth HC-05 Configurer **********");
  Serial.println("1. Name");
  Serial.println("2. Password");
  Serial.println("3. UART");
  Serial.println("4. Role");
  Serial.println("5. cmode");
  Serial.println("6. Bind");
  Serial.println("7. Print module info");
  Serial.println("8. Set operation mode");
  int option = SerialInput("Option: ").toInt();

  switch(option){
    case 1:
      name = SerialInput("Enter name: ");
      sendCommand("AT+NAME=" + name);
      break;
    case 2:
      pswd = SerialInput("Enter password: ");
      sendCommand("AT+PSWD=" + pswd);
      break;
    case 3:
      baud = SerialInput("Enter baud rate: ");
      stop = SerialInput("Enter stop bit: ");
      parity = SerialInput("Enter parity bit: ");
      sendCommand("AT+UART=" + baud + "," + stop + "," + parity);
      break;
    case 4:
      role = SerialInput("Enter role: \n0. Slave \n1. Master");
      sendCommand("AT+ROLE=" + role);
      break;
    case 5:
      cmode = SerialInput("Enter mode: \n0. Fixed address \n 1.Any address");
      sendCommand("AT+CMODE=" + cmode);
      break;
    case 6:
      bind = SerialInput("Enter fixed address: ");
      sendCommand("AT+BIND=" + bind);
      break;
    case 7:
      printInfo();
      break;
    case 8:
      operation = true;
      operationMode();
      break;
    default:
      Serial.println("Wrong option.");
  }
}

//*******************************************************************************************
void setup() {
  Serial.begin(9600);
  configurationMode();
}

void loop() {
  if(!operation) bluetoothConfigurerCLI();
  else SerialCommunication();
}
