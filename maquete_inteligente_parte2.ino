//Definindo variaveis
#define ledP 4
#define potPin A0
#define ldr A2

//Definindo valores para variaveis
int valPot = 0, vldr = 0, led = 2, led2 = 3, sinal = 8, sinal2 = 9;

void setup(){
  pinMode(ledP, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sinal, INPUT);
  pinMode(sinal2, INPUT);
  Serial.begin(9600);

}

void loop(){
  //Parte para corrigir em maquete_inteligente_parte1 parte1
  vldr = analogRead(ldr);
  
  if(vldr < 222){
    valPot = analogRead(potPin);
    valPot = map(valPot, 0, 1023, 0, 255);
    analogWrite(ledP, valPot);
  }else
    analogWrite(ledP, HIGH);
  //Final parte para corrigir.

  //Funcionalidade controla um semaforo de pedestres.
  digitalWrite(led,LOW);
  digitalWrite(led2,HIGH);
  if((digitalRead(sinal)==LOW) && (digitalRead(sinal2)==LOW)){
    digitalWrite(led,LOW);
  }
  if((digitalRead(sinal)==HIGH) || (digitalRead(sinal2)==HIGH)){
    delay(2000);
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
    delay(2000);
    
  }
  //Final funcionalidade.

  //Codigo abaixo usado para verificar valor vldr.
  Serial.println(vldr);
  
}
