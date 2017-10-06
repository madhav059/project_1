#include <SoftwareSerial.h>
#define RX 10 //connect BT TX pin
#define TX 11 // Connect BT RX pin
#define led1 4
#define led2 5
#define led3 6
int a=0;
SoftwareSerial btSerial(RX,TX);
void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  btSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (btSerial.available() > 0)
  {
    a = btSerial.read();
    if (a==1)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if (a==2)
    {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led3, LOW);
    }
    else
    {
       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
       digitalWrite(led3, HIGH);
    }
    a=0;
  }

}
