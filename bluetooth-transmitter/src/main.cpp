#include <Arduino.h>

#define BAUD_RATE 9600

//Push buttons

//Switches

//Potentiometers
class Joystick{
  private:
    int pinX,
        pinY,
        valX,
        valY;
  public:
    Joystick(int pinX, int pinY){
      this->pinX = pinX;
      this->pinY = pinY;
      this->valX = 0;
      this->valY = 0;
    }

    int getValX() {return this->valX;}
    int getValY() {return this->valY;}

    bool update(){
      int x = analogRead(pinX);
      int y = analogRead(pinY);
      if(x != this->valX || y != this->valY){
        this->valX = x;
        this->valY = y;
        return true;
      }
      return false;
    }

    void val2Serial(String xCommand, String yCommand){
      if(update()){
        Serial.println(xCommand + String(this->valX));
        Serial.println(yCommand + String(this->valY));
      }
    }
};

//*****************************************************
//Make a library from this and prove it
/*
Poten pot(A0);
if(pot.update()){
  analogWrite(ledPin, pot.value());
}
 */
class Poten{
  private:
    int pin,
        val;
    private:
      Poten(int pin){
        this->pin = pin;
        this->val = 0;
      }

      int value(){return this->val;}
      bool update(){
        int read = analogRead(this->pin);
        if(read != this->val){
          this->val = read;
          return true;
        }
        else return false;
      }
};


//MPU6050

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
}