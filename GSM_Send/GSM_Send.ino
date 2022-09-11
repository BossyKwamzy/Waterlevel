#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM900
SoftwareSerial mySerial(7, 8); 
const int total_height = 150; // Tank height in CM
const int hold_height = 144;// Water hold height in CM


char cntry_code[] = "+254"; 
char ph[] = "0722831793"; 

const int trigger = 2;
const int echo = 3;
int var_1 = 0;
char input_string[15];

long Time;
int distanceCM;
int resultCM;
int tnk_lvl = 0;
int sensr_to_wtr = 0;
void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM900
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Handshaking with SIM900
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+254745450927\"");
  updateSerial();
  mySerial.print("System Ready"); //text content
  updateSerial();
  mySerial.write(26);
}

void loop()
{
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
void serialEvent()
{
  while (Serial.available())
  {
    if (Serial.find("/"))
    {
      delay(1000);
      while (Serial.available())
      {
        char input_char = Serial.read();
        input_string[var_1++] = input_char;
        if (input_char == '/')
        {
          if (!(strncmp(input_string, "status", 6)))
          {
            measure();
            Serial.print("AT+CMGS=");
            Serial.print("\"");
            Serial.print(cntry_code);
            Serial.print(ph);
            Serial.println("\"");
            delay(1000);
            Serial.print("Tank water level is: ");
            Serial.print(tnk_lvl);
            Serial.println("%");
            delay(100);
            Serial.println((char)26);
          }
          var_1 = 0;
          return;
        }
      }
    }
  }
}
void measure()
{
  delay(100);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  Time = pulseIn(echo, HIGH);
  distanceCM = Time * 0.034;
  resultCM = distanceCM / 2;

  tnk_lvl = map(resultCM, sensr_to_wtr, total_height, 100, 0);
  if (tnk_lvl > 100) tnk_lvl = 100;
  if (tnk_lvl < 0) tnk_lvl = 0;
}
