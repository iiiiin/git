#include <SoftwareSerial.h>
#include <Arduino.h>
#include <Servo.h>

int pos = 90;

//1번이 600, 2번이 450, 3번이 174.(각각44.8,33.05,8.68)
int DIR = 4;
int PWM = 5;
int blueTx = 6;
int blueRx = 7;
SoftwareSerial BTSerial(blueTx,blueRx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(DIR, OUTPUT);
  pinMode(PWM, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String strCmd;
  if(BTSerial.available())
  {
    strCmd = BTSerial.readString();
    Serial.println(strCmd);
    if(strCmd == "l")
    {
      analogWrite(PWM, 0);
      digitalWrite(DIR, HIGH);
      delay(50);
      analogWrite(PWM, 50);
      digitalWrite(DIR, HIGH);
      delay(50);
      analogWrite(PWM, 100);
      digitalWrite(DIR, HIGH);
      delay(50);
      analogWrite(PWM, 150);
      digitalWrite(DIR, HIGH);
      delay(50);
      analogWrite(PWM, 200);
      digitalWrite(DIR, HIGH);
      delay(50);
    }
    else if(strCmd == "s")
    {
      analogWrite(PWM, 0);     
    }
    else if(strCmd == "r")
    {
      analogWrite(PWM, 0);
      digitalWrite(DIR, LOW);
      delay(50);
      analogWrite(PWM, 50);
      digitalWrite(DIR, LOW);
      delay(50);
      analogWrite(PWM, 100);
      digitalWrite(DIR, LOW);
      delay(50);
      analogWrite(PWM, 150);
      digitalWrite(DIR, LOW);
      delay(50);
      analogWrite(PWM, 200);
      digitalWrite(DIR, LOW);
      delay(50);
    }
  }
}
