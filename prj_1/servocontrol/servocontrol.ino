#include <SoftwareSerial.h>
#include <Arduino.h>
#include <Servo.h>

int pos = 90;
Servo myservo;

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
  myservo.attach(9);
  myservo.write(8.68);
  Serial.println("Comand input online, write command to perform action");
  Serial.println("-------------------------");

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
      Serial.print(">");
      int state=44.81;
      Serial.println(state);
      Serial.print("turning servo to ");
      Serial.print(state);
      Serial.println(" degrees");
      myservo.write(80);
      delay(1000);
      myservo.write(state);
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




  
