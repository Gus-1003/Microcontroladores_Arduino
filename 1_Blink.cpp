// Link da simulação: https://www.tinkercad.com/things/22mCf2iEIV4

define led 2
  
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
