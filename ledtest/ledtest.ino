const int trigPin = 12;
const int echoPin = 13;
int ledA=2;
int ledB=3;
int ledC=4;
int ledD=5;
int ledE=9;

int a=9;
int b=8;
int c=6;
int d=4;
int e=2;
int max_distance = 200;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode (ledA,OUTPUT);
pinMode (ledB,OUTPUT);
pinMode (ledC,OUTPUT);
pinMode (ledD,OUTPUT);
pinMode (ledE,OUTPUT);

digitalWrite(ledA, LOW);
digitalWrite(ledB, LOW);
digitalWrite(ledC, LOW);
digitalWrite(ledD, LOW);
digitalWrite(ledE, LOW);
}
void loop() {
// put your main code here, to run repeatedly:
long duration, inches, cm;
pinMode(trigPin,OUTPUT);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
//cm = ( duration / 29 ) / 2;
//inches = cm * 0.393701;
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
if (inches <max_distance){ Serial.print(inches); Serial.print(" in"); Serial.print(cm); Serial.print(" cm"); Serial.println(); delay(100); } //digitalWrite (ledA,HIGH); if (inches >=a) {digitalWrite (ledA,HIGH);digitalWrite (ledB,LOW); digitalWrite (ledC,LOW); digitalWrite (ledD,LOW); }
else if (inches >=b){digitalWrite (ledA,LOW);digitalWrite (ledB,HIGH); digitalWrite (ledC,LOW); digitalWrite (ledD,LOW); digitalWrite (ledE,LOW); }
else if (inches >=c){digitalWrite (ledA,LOW);digitalWrite (ledB,LOW); digitalWrite (ledC,HIGH); digitalWrite (ledD,LOW); digitalWrite (ledE,LOW); }
else if (inches >=d){digitalWrite (ledA,LOW);digitalWrite (ledB,LOW); digitalWrite (ledC,LOW); digitalWrite (ledD,HIGH); digitalWrite (ledE,LOW); }
else if (inches >=e){digitalWrite (ledA,LOW);digitalWrite (ledB,LOW); digitalWrite (ledC,LOW); digitalWrite (ledD,LOW); digitalWrite (ledE,HIGH); }
//else {digitalWrite (ledA,HIGH);digitalWrite (ledB,HIGH); digitalWrite (ledC,HIGH); digitalWrite (ledD,HIGH); }
}
long microsecondsToInches(long microseconds) {
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
// See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
return (microseconds / 74) / 2;
}
long microsecondsToCentimeters(long microseconds) {
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return (microseconds / 29) / 2;
}
