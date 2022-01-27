//Link: https://www.tinkercad.com/things/grsWi32zo66

#include <IRremote.h>

byte pinoIR = 10;
byte lamp1 = 3;
byte lamp2 = 2;

IRrecv sensorIR(pinoIR);
decode_results acao;

void setup(){
  
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  Serial.begin(9600);
  sensorIR.enableIRIn(); 
}

void loop() {
  if(sensorIR.decode(&acao)) {
	Serial.print("Valor lido: ");
        Serial.println(acao.value, HEX);
    
     if(acao.value == 0xFD08F7) {
    		digitalWrite(lamp1, HIGH);
   	 } else if(acao.value == 0xFD8877) {
    		digitalWrite(lamp2, HIGH);
   	 }
      
   	 sensorIR.resume();   	 
  } 
}
