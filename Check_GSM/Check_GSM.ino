void setup()
{
  delay(20000);
  delay(20000);
  delay(20000);
  Serial.begin(9600);
  Serial.println("AT+CMGF=1");  //SMS text mode  
  delay(1000);  
  Serial.println("AT+CMGS=\"+254xxxxxxxxxx\"\r"); // Replace x with recipient's ph no. // Sending/Receiving text
  delay(1000);
  Serial.println("GSM Modem is okay!");
  delay(100);
  Serial.println((char)26); 
  delay(1000);
}
void loop() 
{
  
}
