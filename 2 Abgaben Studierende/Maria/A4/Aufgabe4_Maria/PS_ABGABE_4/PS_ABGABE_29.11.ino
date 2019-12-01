#include <Servo.h>

#define LICHT1 0
#define BEWEGUNG 1
int STATE=0;

long zeit1=0;
long zeit2=1000;
long interval=1000;

Servo MOTOR;
int ROT=2;
int BLAU=9;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
MOTOR.attach(11);
pinMode(ROT,OUTPUT);
pinMode(BLAU,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
stateMachine();
}

void stateMachine() {
 // mein Wunsch
switch(STATE) {
  case LICHT1:
  if(millis() - zeit1 > interval){
    zeit1=millis();
    MOTOR.write(0);
    digitalWrite(ROT,HIGH);
    delay(interval);
    digitalWrite(ROT,LOW);
   STATE=BEWEGUNG;
  }
  break;

  case BEWEGUNG: 
   if(millis() - zeit2 > interval){
    zeit2=millis();
    MOTOR.write(90);
    digitalWrite(BLAU,HIGH);
    delay(interval);
    digitalWrite(BLAU,LOW);
   STATE=LICHT1;
  }
  break;
 
}
}
