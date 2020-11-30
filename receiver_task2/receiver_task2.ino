
 #include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() 
{
  lcd.begin(20,4);
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() 
{

  // print the string when a newline arrives:
  if (stringComplete)
  {
    if(inputString[0] != 0x0A)
 {
    lcd.setCursor(0,0);
    lcd.print("TEMP:");
    lcd.print(inputString[0]);
    lcd.print(inputString[1]);
    Serial.print("FSR1:");
    Serial.print(inputString[0]);
    Serial.print(inputString[1]);
    lcd.setCursor(0,1);
    lcd.print("TEMP1:");
    lcd.print(inputString[2]);
    lcd.print(inputString[3]);
     Serial.print("FSR2:");
    Serial.print(inputString[2]);
    Serial.print(inputString[3]);
    if(inputString[4] == '1')
   { 
    lcd.setCursor(0,2);
    lcd.print("Button 1 pressed");
     Serial.print("FSR3:");
    Serial.print(inputString[4]);
    
   }
   else if(inputString[4] == '2')
   {
      lcd.setCursor(0,2);
    lcd.print("Button 1 not pressed");
     Serial.print("FSR3:");
    Serial.print(inputString[4]);
    
   }
    if(inputString[5] == '3')
   {
     
     lcd.setCursor(0,3);
    lcd.print("Button 2 pressed");
     Serial.print("FSR4:");
    Serial.println(inputString[5]);
   }
    else if(inputString[5] == '4')
   {
     
     lcd.setCursor(0,3);
    lcd.print("Button 2 not pressed");
     Serial.print("FSR4:");
    Serial.println(inputString[5]);
   }
 }
   
    
    
    if(inputString[0]==0x0A)
    {
    lcd.setCursor(0,0);
    lcd.print("TEMP:");
    lcd.print(inputString[1]);
    lcd.print(inputString[2]);
    Serial.print("FSR1:");
    Serial.print(inputString[1]);
    Serial.print(inputString[2]);
    lcd.setCursor(0,1);
    lcd.print("TEMP1:");
    lcd.print(inputString[3]);
    lcd.print(inputString[4]);
     Serial.print("FSR2:");
    Serial.print(inputString[3]);
    Serial.print(inputString[4]);
    if(inputString[5] == '1')
   { 
    lcd.setCursor(0,2);
    lcd.print("Button 1 pressed");
    Serial.print("FSR3:");
    Serial.print(inputString[5]);
    
   }
   else if(inputString[5] == '2')
   {
      lcd.setCursor(0,2);
    lcd.print("Button 1 not pressed");
    Serial.print("FSR3:");
    Serial.print(inputString[5]);
   
   }
    if(inputString[6] == '3')
   {
     
     lcd.setCursor(0,3);
    lcd.print("Button 2 pressed");
     Serial.print("FSR4:");
    Serial.println(inputString[6]);
      }
    else if(inputString[6] == '4')
   {
     
     lcd.setCursor(0,3);
    lcd.print("Button 2 not pressed");
     Serial.print("FSR4:");
    Serial.println(inputString[6]);
  
   }
  }
    
    
  //  Serial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent()
{
  while (Serial.available()>0)
  {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == 0x0D) 
    {
      stringComplete = true;
    } 
  }
}


