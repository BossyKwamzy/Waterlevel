const int trig = 12;
const int echo = 13;

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
    
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(10000);
  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);

}
