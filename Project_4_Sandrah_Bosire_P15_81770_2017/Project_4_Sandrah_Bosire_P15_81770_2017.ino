#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int tempin = A0; // the output pin of TMP36
int temp;
int cel;
int tempmax = 49.152;
int tempmin = 34.816;
int relay = 7;
void setup() {
  pinMode(tempin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(relay, OUTPUT);

}

void loop() {
  temp = analogRead(tempin);
  cel = temp * 0.48828125;
  Serial.print(cel);
  Serial.println();
  
  
  if (temp < tempmin || temp > tempmax ) {
    lcd.setCursor(0, 1);// move cursor to next line
    lcd.print("Relay Status:");
    lcd.print("ON"); // display the temperature
    digitalWrite(relay, LOW);
  }
  
  
   else{
    lcd.setCursor(0, 1);// move cursor to next line
    lcd.print("Relay Status:");
    lcd.print("OFF"); // display the temperature
    digitalWrite(relay, HIGH);
   }

  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.print(cel); // display the temperature
  lcd.print("C ");
  delay(3000);
  lcd.clear();
}
