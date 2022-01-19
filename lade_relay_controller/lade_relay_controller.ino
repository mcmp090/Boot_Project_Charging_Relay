// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
char c;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  switch (c){
    case '1':
    land_motor();
    break;
    case '2':
    land_licht();
    break;
    case '3':
    solar_motor();
    break;
    case '4':
    solar_licht();
    break;
    case '5':
    Stop();
    break;
    default:
    break;
  }

}

void land_motor(){
  Stop();
  Serial.println("-1-");
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(7,LOW);
}

void land_licht(){
  Stop();
  Serial.println("-2-");
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  delay(1000);
  digitalWrite(7,LOW);
}

void solar_motor(){
  Stop();
  Serial.println("-3-");
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  delay(1000);
  digitalWrite(6,LOW);
}

void solar_licht(){
  Stop();
  Serial.println("-4-");
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(6,LOW);
}

void Stop(){
  Serial.println("-5-");
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
}
