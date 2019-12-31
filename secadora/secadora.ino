#include <LiquidCrystal.h>
unsigned long timenow=0,up=12,down=9,start=8,pause=7;
unsigned long timedelay=10000000;//<180 min
unsigned long hora=3600000,minuto=60000,segundo=999;
int h=0,m=0,s=0;
char a[100];
 LiquidCrystal lcd (13,10,6,5,4,3);
void setup() {
 //2,3,4,5,6,7 para el display
lcd.begin(16,2);
 pinMode(2,OUTPUT);
 pinMode(pause,INPUT_PULLUP);
 pinMode(start,INPUT_PULLUP);
 pinMode(down,INPUT_PULLUP);
 pinMode(up,INPUT_PULLUP);
 digitalWrite(2,LOW);
}

void loop() {
  /*7=+10,9=-10,12=pause*/
 if (digitalRead(up)==LOW){
  m=m+10;
  if (m>=60){
    m=m-60;
    h++;
    }
    hour();
    delay(450);}
     if (digitalRead(down)==LOW){
  m=m-10;
  if (m<0){
    m=m+60;
    h--;
    if(h<0){
      h=0;
      m=0;
      s=0;
    }
    }
    hour();
    delay(450);}
  
 digitalWrite(2,LOW); 
 lcd.setCursor(0,0);
 lcd.print("SECADORA STANDBY");
 lcd.setCursor(0,1);
 hour();
 if (digitalRead(start)==LOW){
  delay(25);
  if(digitalRead(start)==LOW){
    delay(25);
    if(digitalRead(start)==LOW){
    delay(25);
    if(digitalRead(start)==LOW){
    delay(25);
    if(digitalRead(start)==LOW){
    delay(25);
    if(digitalRead(start)==LOW){
    delay(25);
    if(digitalRead(start)==LOW){
    delay(25);
    if(digitalRead(start)==LOW){
    delay(25);
    if(digitalRead(start)==LOW){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,0);
      lcd.print("SECADORA  ACTIVO");
      hour();
      timenow=millis();
      hora=millis();
      minuto=millis();
      while(millis()-timenow<=timedelay){
        digitalWrite(2,HIGH);
        if(digitalRead(pause)==LOW){
          delay(25);
          if(digitalRead(pause)==LOW){
          delay(25);
          if(digitalRead(pause)==LOW){
          delay(25);
          if(digitalRead(pause)==LOW){
          delay(25);
          if(digitalRead(pause)==LOW){
          delay(25);
          if(digitalRead(pause)==LOW){
          delay(25);
          if(digitalRead(pause)==LOW){
          delay(25);
          if(digitalRead(pause)==LOW){
            delay(25);
            if (digitalRead(pause)==LOW){
          break;}   }}}}}}}}
        if(h==0 && m==0 && s==0){
          break;}     
        if(millis()-minuto>=segundo){
          minuto=millis();
          s--;
          if(s<0){
            s=59;
            m--;
            if (m<0){
              m=59;
              h--;
            }
          }
          hour();        
        }
        
                
      }  }  } }}}}}}}
}
void hour(){
  lcd.setCursor(4,1);
      sprintf(a,"%02d:%02d:%02d",h,m,s);
      lcd.print(a);/*
      lcd.setCursor(7,1);
      lcd.print(m);
      lcd.setCursor(10,1);
      lcd.print(s);*/
      }
