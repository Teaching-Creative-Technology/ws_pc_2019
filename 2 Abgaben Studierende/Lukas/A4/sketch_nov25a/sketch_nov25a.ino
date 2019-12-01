#define WINKEN 1
#define NICHTWINKEN 0

int state = 0;

#include <Servo.h>;
Servo myservo;


int rot = 8;
int gruen = 11;


long time1 = 0;
long time2 = 1000;

long interval = 1000;

void setup() {
  // put your setup code here, to run once:


  Serial.begin(9600);
  myservo.attach(3);
  pinMode (rot, OUTPUT);
  pinMode (gruen, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
stateMachine();
}



void stateMachine() {
  switch (state){
    case NICHTWINKEN:
    if(millis()-time1>interval){
      time1=millis();
      myservo.write(0);
      digitalWrite(rot, HIGH);
      delay(interval*2); 
      digitalWrite(rot,LOW);
      state=WINKEN;
      
    }
    break;

    case WINKEN:
    if(millis()-time1>interval){
      time1=millis();
      myservo.write(45);
      digitalWrite(gruen, HIGH);
      delay(interval); 
      myservo.write(0);
      delay(interval); 
      myservo.write(45);
      delay(interval); 
      myservo.write(0);
      digitalWrite(gruen,LOW);
      state=NICHTWINKEN;
      
    }
    break;
  }
}
