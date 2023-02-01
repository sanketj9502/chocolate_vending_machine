//#include<LiquidCrystal.h>
//LiquidCrystal lcd(4,5,6,7,8,9);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int i = 0;  int count = 0;  int amount = 0;

int sw1 = 0;
int sw2 = 0;
int sw3 = 0;
int sen = 0;
int flag = 0;
int counter = 0;

void coinInterrupt()
{
  count = count+1;
  i=0;
}

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), coinInterrupt, RISING);  

  lcd.begin();

  pinMode(14,INPUT_PULLUP);
  pinMode(15,INPUT_PULLUP);
  pinMode(16,INPUT_PULLUP);

  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
}

void loop() {
  sw1 = digitalRead(15);
  sw2 = digitalRead(14);
  sw3 = digitalRead(16);
  sen = digitalRead(8);
  
  i=i+1;
  if(i>=30 and count==1)
  {
    amount = amount+10;count = 0;
  flag = 1;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PRESS BUTTON");
  lcd.setCursor(0,1);
  lcd.print("1/2/3 FOR CHIPS");
  delay(1000);
  }

  if(flag == 1)
  {
      if(sw1 == LOW)
      {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DESPENCING");
  lcd.setCursor(0,1);
  lcd.print("LAYS CHIPS.....");
  digitalWrite(5,HIGH);
       }

      if(sw2 == LOW)
      {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DESPENCING");
  lcd.setCursor(0,1);
  lcd.print("TANGO CHIPS.....");
  digitalWrite(6,HIGH);
      }

      if(sw3 == LOW)
      {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DESPENCING");
  lcd.setCursor(0,1);
  lcd.print("NACHOS CHIPS.....");
  digitalWrite(7,HIGH);
      }
  }
  else
  {
    counter++;

if(counter < 15){
    Serial.println(amount);
 if(counter == 1){lcd.clear();}
  lcd.setCursor(0,0);
  lcd.print("Welcome TO chips");
  lcd.setCursor(0,1);
  lcd.print("Vending Machine");
  delay(100);
}
if(counter <30 && counter > 15){
  if(counter == 16){lcd.clear();}
  lcd.setCursor(0,0);
  lcd.print("PLEASE INSERT");
  lcd.setCursor(0,1);
  lcd.print("     COIN!!!");
  delay(100);
}
if(counter > 30){counter = 0;}
  }
if(sen == LOW)
{
  flag = 0;
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("THANK YOU!!!");
  lcd.setCursor(0,1);
  lcd.print("VISIT AGAIN....");
  delay(2000);

}
  
}

 
