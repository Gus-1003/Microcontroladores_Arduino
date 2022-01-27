#include <Wire.h>

const byte entrada1 = 11; //Motor da Direita - Acelerar
const byte entrada2 = 12; //Motor da Direita - Ré
const byte vel1 = 10;      //Velocidade = Ativação do motor

void setup(){
  Wire.begin(1);

  pinMode(vel1, OUTPUT); //Velocidade - Motor

  pinMode(entrada1, OUTPUT); //Motor da Direita - Acelerar
  pinMode(entrada2, OUTPUT); //Motor da Direita - Ré

  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop(){
  delay(100);
}

void receiveEvent(int howMany) {//howMany indica o número de bytes a serem lidos
  bool x = Wire.read();
  Serial.println(x);
  
  if (x){
    analogWrite(vel1, 255);
    digitalWrite(entrada1, LOW);
    digitalWrite(entrada2, HIGH);
  }else{
    analogWrite(vel1, 0);
    digitalWrite(entrada1, LOW);
    digitalWrite(entrada2, LOW);
  }
}
