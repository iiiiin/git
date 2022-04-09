#include <SoftwareSerial.h>
#include <Arduino.h>

int blueTx = 2;
int blueRx = 3;
SoftwareSerial BTSerial(blueTx,blueRx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available()){
    Serial.write(BTSerial.read());
  }
  if (Serial.available()){
    BTSerial.write(Serial.read());
  }
}
