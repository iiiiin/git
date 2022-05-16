#include <SoftwareSerial.h>
#include <Arduino.h>
#include <Servo.h>
#include <EEPROM.h>

//1번이 600, 2번이 450, 3번이 174.(각각44.8,33.05,8.68)
int DIR = 4;
int PWM = 5;
int blueTx = 6;
int blueRx = 7;
String i = "174";
SoftwareSerial BTSerial(blueTx,blueRx);
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(DIR, OUTPUT);
  pinMode(PWM, OUTPUT);
  myservo.attach(9);
  myservo.write(8.68);
  BTSerial.println("Enter the Degrees :");
}

void up276() {
  myservo.write(80);
  analogWrite(PWM, 0);
  digitalWrite(DIR, HIGH);
  delay(1000);
  analogWrite(PWM, 50);
  digitalWrite(DIR, HIGH);
  delay(1000);
  analogWrite(PWM, 0);
  digitalWrite(DIR, HIGH);
  delay(1000);
  myservo.write(33.05);
}
void up426() {
  myservo.write(80);
  analogWrite(PWM, 0);
  digitalWrite(DIR, HIGH);
  delay(1000);
  analogWrite(PWM, 50);
  digitalWrite(DIR, HIGH);
  delay(1000);
  analogWrite(PWM, 0);
  digitalWrite(DIR, HIGH);
  delay(1000);
  myservo.write(44.8);
}
void up150() {
  myservo.write(80);
  analogWrite(PWM, 0);
  digitalWrite(DIR, HIGH);
  delay(1000);
  analogWrite(PWM, 50);
  digitalWrite(DIR, HIGH);
  delay(1000);
  analogWrite(PWM, 0);
  digitalWrite(DIR, HIGH);
  delay(1000);
  myservo.write(44.8);
}
void dn276() {
  myservo.write(80);
  analogWrite(PWM, 0);
  digitalWrite(DIR, LOW);
  delay(1000);
  analogWrite(PWM, 50);
  digitalWrite(DIR, LOW);
  delay(1000);
  analogWrite(PWM, 0);
  digitalWrite(DIR, LOW);
  delay(1000);
  myservo.write(8.68);
}
void dn426() {
  myservo.write(80);
  analogWrite(PWM, 0);
  digitalWrite(DIR, LOW);
  delay(1000);
  analogWrite(PWM, 50);
  digitalWrite(DIR, LOW);
  delay(1000);
  analogWrite(PWM, 0);
  digitalWrite(DIR, LOW);
  delay(1000);
  myservo.write(8.68);
}
void dn150() {
  myservo.write(80);
  analogWrite(PWM, 0);
  digitalWrite(DIR, LOW);
  delay(1000);
  analogWrite(PWM, 50);
  digitalWrite(DIR, LOW);
  delay(1000);
  analogWrite(PWM, 0);
  digitalWrite(DIR, LOW);
  delay(1000);
  myservo.write(33.05);
}

void loop() {
  // put your main code here, to run repeatedly:
  String strCmd;
  if(BTSerial.available())
  {
    EEPROM.get(0,i);
    strCmd = BTSerial.readString();
    Serial.println(strCmd);
    if(i == "600")
    {
      if(strCmd == "450")
      {
        dn150();
        i = strCmd;
      }
      else if(strCmd == "174")
      {
        dn426();
        i = strCmd;
      }
    }
    if(i == "450")
    {
      if(strCmd == "600")
      {
        up150();
        i = strCmd;
      }
      else if(strCmd == "174")
      {
        dn276();
        i = strCmd;
      }
    }
    if(i == "174")
    {
      if(strCmd == "600")
      {
        up426();
        i = strCmd;
      }
      else if(strCmd == "450")
      {
        up276();
        i = strCmd;
      }
    }
    EEPROM.put(0,i);
  }
}
