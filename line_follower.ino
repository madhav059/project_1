
#include <SoftwareSerial.h>
#define LS 2      // left sensor
#define RS 3      // right sensor
#define LM1 7    // left motor
#define LM2 6    // left motor
#define RM1 8    // right motor
#define RM2 9    // right motor
#define RX 0
#define TX 1   
                                                                                                        
SoftwareSerial btSerial(RX, TX);
//int state=0;
void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  btSerial.begin(38400);
}

void loop() {

 //if (btSerial.available() > 0)
  //state=btSerial.read();

 if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    btSerial.write(1);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    btSerial.write(2);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    btSerial.write(3);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
   btSerial.write(4);
  }

}
