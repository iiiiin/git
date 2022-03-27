// ** 종합설계_아두이노_BLDC_모터제어 **
// 아두이노 - 모터드라이버 연결 (PWM, DIR, GND)

# include <SoftwareSerial.h>

SoftwareSerial BTSerial(#,#)            //(RX, TX)
int DIR = #                             // DIGITAL OUT 에서 번호 설정
int PWM = #                             // DIGITAL OUT 에서 번호 설정


void setup()
{
	pinMode(DIR, OUTPUT);               // DIR 출력으로 사용
    pinMode(PWM, OUTPUT);               // PWM 출력으로 사용
    Serial.begin(9600);                 // baud rate 9600
    BTserial.begin(9600);
}

void loop()
{
	String cmnd;                        // cmnd : 입력받는 목표 높이
    if(BTSerial.available())            // 블루투스 시리얼 통신
    {
        #########                       // 현재 높이를 확인하는 알고리즘 (추가) "현재 높이를 변수로 할당하여 중첩 if문" "모터의 회전 > 변수"
        cmnd = BTSerial.readString();   // 블루투스 시리얼 통신으로 입력받은 값 string 형태로 cmnd 할당
        if(cmnd == "450")               // 목표 높이 : 450mm
        {
            if(# = "000")               // 현재 높이 : 최소높이 
            {
                analogWrite(PWM, 0);    // 회전속도 설정
                digitalWrite(DIR, HIGH);// 회전방향 설정
                delay(50);
            }
            else if(# = "600")          // 현재 높이 : 600mm
            {
                analogWrite(PWM, 0);    // 회전속도 설정
                digitalWrite(DIR, LOW); // 회전방향 설정 (역)
                delay(50);
            }
            else if(# = "450")          // 현재 높이 : 450mm
            {}                          // 정지 (동작 X)
        }
        else if(cmnd == "600")          // 목표 높이 : 600mm
        {
            if(# = "000")               // 현재 높이 : 600mm
            {
                analogWrite(PWM, 0);    // 회전속도 설정
                digitalWrite(DIR, HIGH);// 회전방향 설정
                delay(50);
            }
            else if(# = "450")          // 현재 높이 : 최소높이
            {
                analogWrite(PWM, 0);    // 회전속도 설정
                digitalWrite(DIR, HIGH);// 회전방향 설정
                delay(50);
            }
            else if(# = "600")          // 현재 높이 600mm
            {}                          // 정지 (동작 X)
        }
        else if(cmnd == "000")          // 목표 높이 : 최소높이
        {
            if(# = "600")               // 현재 높이 : 600mm
            {
                analogWrite(PWM, 0);    // 회전속도 설정
                digitalWrite(DIR, LOW); // 회전방향 설정 (역)
                delay(50);
            }
            else if(# = "450")          // 현재 높이 : 최소높이
            {
                analogWrite(PWM, 0);    // 회전속도 설정
                digitalWrite(DIR, LOW); // 회전방향 설정 (역)
                delay(50);
            }
            else if(# = "000")          // 현재 높이 최소높이
            {}                          // 정지 (동작 X)

        }
    }
}


