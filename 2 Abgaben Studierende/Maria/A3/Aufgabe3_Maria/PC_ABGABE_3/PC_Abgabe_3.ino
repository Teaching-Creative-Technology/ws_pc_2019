int photo = A2;
int led = 9;
int widerstand;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(photo,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
widerstand=analogRead(photo);
Serial.println(widerstand);
widerstand=map(widerstand,450,700,0,255);
analogWrite(led,widerstand);
}
