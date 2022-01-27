#include <Wire.h>
#include <Servo.h>

Servo myservo;  // criar o objeto servo motor de entrada

void setup(){
  Wire.begin(2);
  
  myservo.attach(5);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop(){
}

void receiveEvent(int howMany) {//howMany indica o número de bytes a serem lidos
  
  bool y = Wire.read();
  Serial.println(y);
  
  if (y){
      myservo.write(120);            
      delay(15);
  }else{
      myservo.write(0);            
      delay(15);
  }
}
