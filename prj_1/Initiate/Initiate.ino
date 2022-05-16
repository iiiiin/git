#include <SoftwareSerial.h>
#include <Arduino.h>

int blueTx = 6;
int blueRx = 7;
String i = "174";
SoftwareSerial BTSerial(blueTx,blueRx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  
  String strCmd;
  if(BTSerial.available())
  {
    strCmd = BTSerial.readString();
    Serial.println(strCmd);
    if(i == "600")
    {
      if(strCmd == "450")
      {
        i = strCmd;
        Serial.println(i);
        Serial.println("d150");
      }
      else if(strCmd == "174")
      {
        i = strCmd;
        Serial.println(i);
        Serial.println("d426");
      }
    }
    else if(i == "450")
    {
      if(strCmd == "600")
      {
        i = strCmd;
        Serial.println(i);
        Serial.println("u150");
      }
      else if(strCmd == "174")
      {
        i = strCmd;
        Serial.println(i);
        Serial.println("d276");
      }
    }
    else if(i == "174")
    {
      if(strCmd == "600")
      {
        i = strCmd;
        Serial.println(i);
        Serial.println("u426");
      }
      else if(strCmd == "450")
      {
        i = strCmd;
        Serial.println(i);
        Serial.println("u276");
      }
    }
  }
}
