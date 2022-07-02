// Link da simulação: https://www.tinkercad.com/things/eiZDyHDErpU

const byte botao = 2;
const byte led = 4;
boolean estadoBotao;

void setup() {
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  
  estadoBotao = digitalRead(botao);
  
  switch(estadoBotao) {
        case HIGH: 
            digitalWrite(led,HIGH);
        break;
        case LOW: 
            digitalWrite(led,LOW);
        break;
  }
  
}
