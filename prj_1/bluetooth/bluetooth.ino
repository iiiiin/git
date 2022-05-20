#include <SoftwareSerial.h>
#include <Arduino.h>
#include <Servo.h>


//1번이 600, 2번이 450, 3번이 174.(각각44.8,33.05,8.68)

int DIR = 4;
int PWM = 5;
int blueTx = 6; 
int blueRx = 7;
int val_X;
int val_Y;
int val_Z;
int buzzer = 12;
String i = "174";
SoftwareSerial BTSerial(blueTx,blueRx);
Servo myservo;

void setup() {

  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(DIR, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(buzzer,OUTPUT);
  myservo.attach(9);
  myservo.write(8.68);
  BTSerial.println("Enter the height you want :");
  }

void loop() {

  digitalWrite(buzzer, HIGH);
  val_X = analogRead(A0); 
  val_Y = analogRead(A1);
  val_Z = analogRead(A2);
  Serial.print("X:");
  Serial.print(val_X);
  Serial.print("  Y:");
  Serial.print(val_Y);
  Serial.print("  Z:");
  Serial.println(val_Z);
  Serial.println();
  String strCmd;
  // if(val_X > n || val_Y > n){
  //   digitalWrite(buzzer,LOW);
  //   delay(1000)
  //   digitalWrite(buzzer,HIGH);
  // }
  if(BTSerial.available())
  {
    strCmd = BTSerial.readString();
    Serial.println(strCmd);
    if(i == "600")
    {
      if(strCmd == "450")
      {
        dist(-150);
        i = strCmd;
      }
      else if(strCmd == "174")
      {
        dist(-476);
        i = strCmd;
      }
      else if(strCmd == "0")
      {
        dist(-476);
        i = strCmd;
      }
    }
    if(i == "450")
    {
      if(strCmd == "600")
      {
        dist(150);
        i = strCmd;
      }
      else if(strCmd == "174")
      {
        dist(-276);
        i = strCmd;
      }
      else if(strCmd == "0")
      {
        dist(-276);
        i = strCmd;
      }
    }
    if(i == "174")
    {
      if(strCmd == "600")
      {
        dist(426);
        i = strCmd;
      }
      else if(strCmd == "450")
      {
        dist(276);
        i = strCmd;
      }
    }
  }
}

void dist(int x) {
  if(x == 426)
  {
    myservo.write(80);
    analogWrite(PWM, 0);
    digitalWrite(DIR, HIGH);
    delay(500);
    analogWrite(PWM, 255);
    digitalWrite(DIR, HIGH);
    delay(500);
    analogWrite(PWM, 0);
    digitalWrite(DIR, HIGH);
    delay(500);
    myservo.write(44.8);
  }
  if(x == 276)
  {
    myservo.write(80);
    analogWrite(PWM, 0);
    digitalWrite(DIR, HIGH);
    delay(500);
    analogWrite(PWM, 255);
    digitalWrite(DIR, HIGH);
    delay(500);
    analogWrite(PWM, 0);
    digitalWrite(DIR, HIGH);
    delay(500);
    myservo.write(33.05);
  } 
  if(x == 150)
  {
    myservo.write(80);
    analogWrite(PWM, 0);
    digitalWrite(DIR, HIGH);
    delay(500);
    analogWrite(PWM, 255);
    digitalWrite(DIR, HIGH);
    delay(500);
    analogWrite(PWM, 0);
    digitalWrite(DIR, HIGH);
    delay(500);
    myservo.write(44.8);
  }
  if(x == -426)
  {
    myservo.write(80);
    analogWrite(PWM, 0);
    digitalWrite(DIR, LOW);
    delay(500);
    analogWrite(PWM, 255);
    digitalWrite(DIR, LOW);
    delay(500);
    analogWrite(PWM, 0);
    digitalWrite(DIR, LOW);
    delay(500);
    myservo.write(8.68);
  }
  if(x == -276)
  {
    myservo.write(80);
    analogWrite(PWM, 0);
    digitalWrite(DIR, LOW);
    delay(500);
    analogWrite(PWM, 255);
    digitalWrite(DIR, LOW);
    delay(500);
    analogWrite(PWM, 0);
    digitalWrite(DIR, LOW);
    delay(500);
    myservo.write(8.68);
  }
  if(x == -150)
  {
    myservo.write(80);
    analogWrite(PWM, 0);
    digitalWrite(DIR, LOW);
    delay(500);
    analogWrite(PWM, 255);
    digitalWrite(DIR, LOW);
    delay(500);
    analogWrite(PWM, 0);
    digitalWrite(DIR, LOW);
    delay(500);
    myservo.write(33.05);
  }
}