# include <SoftwareSerial.h>

SoftwareSerial BTSerial(#,#)            //(RX, TX) 순서주의
int DIR = #                             // DIGITAL OUT 에서 번호 설정
int PWM = #

void setup() {

    pinMode(DIR, OUTPUT);               // DIR 출력으로 사용
    pinMode(PWM, OUTPUT);               // PWM 출력으로 사용
    Serial.begin(9600);                 // baud rate 9600
    BTserial.begin(9600);

}

void loop() {
  
  while(BTSerial.available()){
      numbar = BTSerial.readString();
      if (numbar > #){
        analogWrite(PWM, 0);    // 회전속도 설정
        digitalWrite(DIR, LOW); // 모터 역회전
      }
      else break
  }

}
