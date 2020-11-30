
#include<LiquidCrystal.h>;
//int buttonState = 0;// variable for reading the pushbutton status
LiquidCrystal lcd(7,6,5,4,3,2);
int b1 = 8;
int b2 = 9;
void setup() {
  // initialize the LED pin as an output:
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("Welcome to Data");
  lcd.setCursor(0,1);
  lcd.print("Transmission");
  delay(200);
  lcd.clear(); 
}

void loop()
{ 
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int sensorValue = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int TEMP=sensorValue/2;
  int TEMP1=sensorValue1/2;
  lcd.setCursor(0,0);
  lcd.print("TEMP1:");
  lcd.print(TEMP);
  lcd.setCursor(0,1);
  lcd.print("TEMP2:");
  lcd.print(TEMP1);
  
  Serial.print(TEMP);
  Serial.print(TEMP1);
  
  if(digitalRead(b1) == LOW)
  {
     
    lcd.setCursor(0,2);
    lcd.print("Button 1 pressed");
    Serial.print(a);
  }
  else
  {
    
    lcd.setCursor(0,2);
    lcd.print("Button 1 not pressed");
    Serial.print(b);
  }
  if(digitalRead(b2) == LOW)
  {
    
    lcd.setCursor(0,3);
    lcd.print("Button 2 pressed");
    Serial.println(c);
  }
  else
  {
    
    lcd.setCursor(0,3);
    lcd.print("Button 2 not pressed");
    Serial.println(d);
  }
  delay(200);
  
 }
