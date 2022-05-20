#include <SoftwareSerial.h>
#include <Arduino.h>        

// 헤더파일은 vscode 맞춤(무시)

int blueTx = 6;
int blueRx = 7;
String i = "174";
SoftwareSerial BTSerial(blueTx,blueRx);

// 블루투스 모듈 핀 위치 선정, 변수 i 선언 (초기값 : 174)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
}

// 시리얼, 블루투스 통신 보드레이트 맞춤

void loop() {
  
  String strCmd;            // strCmd : 블루투스로 입력받을 변수
  if(BTSerial.available())  // 블루투스 페어링 상태일 경우
  {
    strCmd = BTSerial.readString(); // 블루투스로 입력받은 값 읽음
    Serial.println(strCmd);         // 시리얼모니터에 strCmd 출력
    if(i == "600")                  // i 값이 600 인 경우
    {
      if(strCmd == "450")           // 입력받은 strCmd 값이 450인 경우
      {
        i = strCmd;                 // strCmd 값을 i에 할당
        Serial.println(i);          // 시리얼모니터에 할당된 i 값 출력
        Serial.println("d150");     // d150 함수 실행 (으로 변경 예정)
      }                             // d150 : 150mm 만큼 모터 역회전 함수
      else if(strCmd == "174")
      {
        i = strCmd;
        Serial.println(i);
        Serial.println("d426");
      }
      else if(strCmd == "0")        // 입력받은 strCmd 값이 0인 경우
      {
        Serial.println("base");     // d426 함수 실행 (으로 변경 예정)
      }                             // 각 조건에서 174mm로 가는 함수 실행      
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
      else if(strCmd == "0")
      {
        Serial.println("base");
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
      else if(strCmd == "0")
      {
        Serial.println("base");
      }
    }
  }
}

//   위 언급한 함수(추가 예정)
//   void up276() {
//   myservo.write(80);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   analogWrite(PWM, 50);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   myservo.write(33.05);
// }
// void up426() {
//   myservo.write(80);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   analogWrite(PWM, 50);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   myservo.write(44.8);
// }
// void up150() {
//   myservo.write(80);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   analogWrite(PWM, 50);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, HIGH);
//   delay(1000);
//   myservo.write(44.8);
// }
// void dn276() {
//   myservo.write(80);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   analogWrite(PWM, 50);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   myservo.write(8.68);
// }
// void dn426() {
//   myservo.write(80);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   analogWrite(PWM, 50);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   myservo.write(8.68);
// }
// void dn150() {
//   myservo.write(80);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   analogWrite(PWM, 50);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   analogWrite(PWM, 0);
//   digitalWrite(DIR, LOW);
//   delay(1000);
//   myservo.write(33.05);
// }