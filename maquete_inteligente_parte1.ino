//Definindo variaveis e incluindo bibliotecas
#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define led 3
#define potPin A0
#define ldr A2
#define ledR 2
#define ledY 3
#define ledG 4
#define ledG2 8
#define ledY2 9
#define ledR2 10

//Definindo valores para variaveis
dht DHT;
uint32_t timer = 0;
int a = 1, valPot = 0, vldr = 0;
unsigned long time = 0, val = 1000;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup(){
  lcd.begin (16,2);
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledR2, OUTPUT);
  pinMode(ledY2, OUTPUT);
  pinMode(ledG2, OUTPUT);
  
}

void loop(){
  //.1
  vldr = analogRead(ldr);
  //.1
  
  //Inicia funcionalidade do LCD.
  if(millis() - time >= val){
    if(a == 1){
      lcd.setBacklight(LOW);
      lcd.clear();
      a = 0;
      
    }else if(a == 0){
      DHT.read11(A1); 
      lcd.setBacklight(HIGH);
      lcd.setCursor(0,0);
      lcd.print("Temp: ");
      lcd.setCursor(6,0);
      lcd.print(DHT.temperature);
      lcd.print(" C");
      lcd.setCursor(0,1);
      lcd.print("Humidade: ");
      lcd.print(DHT.humidity,0);
      lcd.print("%");
      a = 1;
      
    }
    time = millis();
  
  }
  //Finaliza funcionalidade do LCD
  
  //Por terminar .1 faz parte da funcao,
  if(vldr < 111){
    valPot = analogRead(potPin);
    valPot = map(valPot, 0, 1023, 0, 255);
    analogWrite(led, valPot);
  }else
    analogWrite(led, HIGH);
  //Por terminar.
  
  //Funcionalidade dos semaforos de um cruzamento, usando a funcao millis.
  if(millis() - timer < 1000){
    digitalWrite(ledR2, HIGH);
    digitalWrite(ledG, HIGH);  
  
  }
  
  if((millis() - timer >= 1000) && (millis() - timer < 3000)){
    digitalWrite(ledY, HIGH);
    digitalWrite(ledG, LOW);  
  
  }    
  
  if((millis() - timer >= 3000) && (millis() - timer < 6000)){
    digitalWrite(ledY, LOW);
    digitalWrite(ledG2, HIGH);
    digitalWrite(ledR, HIGH);  
    digitalWrite(ledR2, LOW);  

  }
  
  if((millis() - timer >= 6000) && (millis() - timer < 7000)){
    digitalWrite(ledR, HIGH);  
    digitalWrite(ledG2, HIGH);
  
  }
  
  if((millis() - timer >= 7000) && (millis() - timer < 9000)){
    digitalWrite(ledY2, HIGH);  
    digitalWrite(ledG2, LOW);
 
  }
  
  if((millis() - timer >= 9000) && (millis() - timer < 12000)){
    digitalWrite(ledY2, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR2, HIGH);  
    digitalWrite(ledR, LOW);  
    
  }
  
  if(millis() - timer > 12000){
    timer = millis();
  
  }
  //Finaliza funcionalidade dos semaforos.
  
}


