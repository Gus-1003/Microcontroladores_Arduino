// Link: https://www.tinkercad.com/things/f1pCvfIn5Fl

const byte pulldown = 2;
const byte pullup = 4;
const byte leddown = 10;
const byte ledup = 11;

void setup(){
  // Entradas de ação:
  pinMode(pulldown, INPUT);
  pinMode(pullup, INPUT);
  // Saidas do Evento:
  pinMode(leddown, OUTPUT);
  pinMode(ledup, OUTPUT);
}


void loop(){
  if (digitalRead(pulldown) == 1){
        digitalWrite(leddown, HIGH);
    } else {
      digitalWrite(leddown, LOW);
    }

  if (digitalRead(pullup) == 0){
        digitalWrite(ledup, HIGH);
    } else {
      digitalWrite(ledup, LOW);
    }
}
