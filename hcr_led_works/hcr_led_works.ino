const int trig = 12;
const int echo = 13;

const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 9;

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  
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
  

  if ( distance <= 5 )
  {
    digitalWrite(LED1, HIGH); digitalWrite (LED2,LOW); digitalWrite (LED3,LOW); digitalWrite (LED4,LOW); digitalWrite (LED5,LOW);
  }
  else
  {
    digitalWrite(LED1, LOW);
  }
  
  if ( 5 <= distance <= 10 )
  {
    digitalWrite(LED2, HIGH); digitalWrite (LED1,LOW); digitalWrite (LED3,LOW); digitalWrite (LED4,LOW); digitalWrite (LED5,LOW);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  
  if ( 10 < distance <= 15 )
  {
    digitalWrite(LED3, HIGH); digitalWrite (LED1,LOW); digitalWrite (LED2,LOW); digitalWrite (LED4,LOW); digitalWrite (LED5,LOW);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }
  
  if ( 15 < distance <= 40 )
  {
    digitalWrite(LED4, HIGH); digitalWrite (LED1,LOW); digitalWrite (LED2,LOW); digitalWrite (LED3,LOW); digitalWrite (LED5,LOW);
  }
  else
  {
    digitalWrite(LED4, LOW);
  }
  
  if ( distance = 144 )
  {
    digitalWrite(LED5, HIGH); digitalWrite (LED1,LOW); digitalWrite (LED2,LOW); digitalWrite (LED3,LOW); digitalWrite (LED4,LOW);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }
}
