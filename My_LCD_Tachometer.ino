

#include <LiquidCrystal.h>

 



LiquidCrystal lcd(13,10,6,5,4,3);

// read the IR sensor on pin 2

const int irPin=2;

const int shiftLed=9;

const unsigned long sampleTime=250;

const int maxRPM = 17970; 

void setup() 

{

  pinMode(irPin,INPUT);

  pinMode(shiftLed,OUTPUT);

   Serial.begin(115200);



  lcd.begin(16, 2);

  // Print a message to the LCD.

  lcd.print("   TACOMETRO");  
  lcd.setCursor(1, 2); 
  lcd.print("     UNTELS") ;
  delay(2500);

  lcd.clear();

}

void loop() 

{

  delay(100);

  int rpm=getRPM();

  lcd.clear();

  displayRPM(rpm);

  displayBar(rpm);

}

int getRPM()

{

  // sample for sampleTime in millisecs

  int count=0;

  boolean kflag=LOW;

  unsigned long currentTime=0;

  unsigned long startTime=millis();

  while (currentTime<=sampleTime)

{

    if (digitalRead(irPin)==HIGH)

{

    kflag=HIGH;

}

if (digitalRead(irPin)==LOW && kflag==HIGH)

{

count++;

kflag=LOW;

}

currentTime=millis()-startTime;

}

int count2rpm = int(7500./float(sampleTime))*count;

return count2rpm;

}

void displayRPM(int rpm) 

{

  lcd.clear();

  // set the cursor to column 0, line 1

  lcd.setCursor(0, 0); 

  // print the number of seconds since reset:

  lcd.print(rpm,DEC);

  

  if((rpm)==3000)  //change value to own choice

{

  digitalWrite(shiftLed,HIGH);

}

else if((rpm)==6000)  //change value to own choice

{

  digitalWrite(shiftLed,HIGH);

}

else if((rpm)==17970)  //Change value to own choice

{

  digitalWrite(shiftLed,HIGH);

}

else

{

  digitalWrite(shiftLed,LOW);

}

  lcd.setCursor(7,0);

  lcd.print("RPM");

}

void displayBar(int rpm)

{

  int numOfBars=map(rpm,0,maxRPM,0,15);

  lcd.setCursor(0,1);

  if (rpm!=0)

{

  for (int i=0; i<=numOfBars; i++)

{

 lcd.setCursor(i,1);

 lcd.write(1023);

}}}
