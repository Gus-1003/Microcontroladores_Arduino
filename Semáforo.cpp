//Link da simulação:https: www.tinkercad.com/things/dZvAMLMFdCT
// Autor: Gustavo Maciel

#define botom 2
#define red1 3
#define ama1 4
#define gren1 5

#define red2 6
#define gren2 7

boolean estadoBotao;

void setup() {
  pinMode(botom, INPUT);

  pinMode(red1, OUTPUT);
  pinMode(ama1, OUTPUT);
  pinMode(gren1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(gren2, OUTPUT);
}

void loop() {
  
  digitalWrite(red1,LOW);
	digitalWrite(ama1,LOW);
	digitalWrite(gren1,HIGH);
	digitalWrite(gren2,LOW);
  digitalWrite(red2,HIGH);
  
  if(digitalRead(botom)) {
    delay(3000);

    digitalWrite(gren1,LOW);
    digitalWrite(ama1,HIGH);

    delay(2000);

    digitalWrite(ama1,LOW);
    digitalWrite(red1,HIGH);
    digitalWrite(red2,LOW);
    digitalWrite(gren2,HIGH);

    delay(10000);

    for (int i = 0; i < 10; i++){
        digitalWrite(gren2,LOW);
        delay(2000);
        digitalWrite(gren2,HIGH);
        delay(2000);
    } 
  }
}
