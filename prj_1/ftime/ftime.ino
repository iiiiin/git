int DIR = 4;
int PWM = 3;
void setup()
{
  pinMode(DIR, OUTPUT);
  pinMode(PWM, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  String strCmd;
  if(Serial.available())
  {
    strCmd = Serial.readString();
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
