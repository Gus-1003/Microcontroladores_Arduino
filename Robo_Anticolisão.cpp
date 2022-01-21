#include <Servo.h>
Servo maquina;  // criar o objeto servo motor de entrada

//----------------------------Pinos----------------------------
const byte entrada1 = 11; //Motor da Direita - Acelerar
const byte entrada2 = 12; //Motor da Direita - Ré
const byte vel1 = 4;      //Valor da velocidade do motor 1

const byte entrada3 = 2;  //Motor da esquerda - Acelerar
const byte entrada4 = 3;  //Motor da esquerda - Ré
const byte vel2 = 13;     //Valor da velocidade do motor 2

const byte ldr = A5; 	// Pino analogico da temperatura

const byte ledR = 6; 	// Pino led Vermelhos
const byte ledG = 7; 	// Pino led verde


const byte trigger = 9; // Pino de controle do gatilho de vibração
const byte echo = 10; // pino responsavel pelo eco

//----------------------------Variáveis-----------------------------
// Váriavel que ira medir a luminosidade:
int estado = 0;
// Váriavel que ira medir a duração da frequência:
float duration;
// Váriavel que ira medir a distâmcia para o obstaculo:
float distance;
//Valor que mede a intensidade da luminosidade:
byte luminosidade = 0;

//----------------------------Setup-----------------------------
void setup() {
  Serial.begin(9600);
  
  pinMode(ldr, INPUT);  // Fotoresistor - Entrada
  pinMode(echo, INPUT); // Echo_Ultrasom - Entrada
  
  pinMode(ledR, OUTPUT); // Led_Vermelho - Saida
  pinMode(ledG, OUTPUT); // Led_verde - Saida
  
  pinMode(trigger, OUTPUT);  
  
  pinMode(vel1, OUTPUT); //Velocidade - Motor da Direita
  pinMode(vel2, OUTPUT); //Velocidade - Motor da Esquerda
  
  pinMode(entrada1, OUTPUT); //Motor da Direita - Acelerar
  pinMode(entrada2, OUTPUT); //Motor da Direita - Ré
  
  pinMode(entrada3, OUTPUT); //Motor da Esquerda - Ré
  pinMode(entrada4, OUTPUT); //Motor da Esquerda - Acelerar
  
  // Reação da maquiana a partir do comando do pino 5:
  maquina.attach(5); 
}
//----------------------------LOOP-----------------------------
void loop() {
  if(luz()){
  	distance = sonar();
  	LedDistance(distance);
  }else{
    pararMotor();
    Serial.println("Baixa Luminosidade"); 
  }	
  delay(100);
}

//----------------------------Luz-----------------------------
bool luz(){
  estado = analogRead(ldr);  
  luminosidade = map(estado, 49, 969, 0, 255);
  if(luminosidade > 200){
    return true;
  }
  return false;
}
//----------------------------Sonar-----------------------------
float sonar() {
  digitalWrite(trigger, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigger, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigger, LOW);  
  duration = pulseIn(echo, HIGH);  
  distance = (duration*.0343)/2;//0.0343 é a velocidade do som em cm/μs
  delay(100);
  Serial.print("Distance: ");  
  Serial.println(distance);
  return distance;
}

//----------------------------Distancia-----------------------------
void LedDistance(float distance){
  if(distance < 30){
    /* Perto de um obstaculo a luz deve ser 
    acesa e os motores devem parar*/
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);
   	pararMotor();
    ligarMotorRe();
    pararMotor();
    posimaquina(90);
    ligarMotor();
    pararMotor();
    posimaquina(0);
    ligarMotor();
  }
  else{
    /* Longe de um obstaculo a luz deve ser 
    acesa e os motores devem parar*/
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    posimaquina(0);
    ligarMotor();
  }
}
// ================= MOTOR ==========================
void ligarMotor(){
  analogWrite(vel1, 255); // Motor da direita
  digitalWrite(entrada1, LOW);
  digitalWrite(entrada2, HIGH);
  
  analogWrite(vel2, 255); // Motor da Esquerda
  digitalWrite(entrada3, HIGH);
  digitalWrite(entrada4, LOW);
  delay(4000);
}

void ligarMotorRe(){
  analogWrite(vel1, 255); // Motor da direita
  digitalWrite(entrada1, HIGH);
  digitalWrite(entrada2, LOW);
  
  analogWrite(vel2, 255); // Motor da Esquerda
  digitalWrite(entrada3, LOW);
  digitalWrite(entrada4, HIGH);
  delay(4000);
}

void pararMotor(){
  analogWrite(vel1, 0); // Motor da Direita
  digitalWrite(entrada1, LOW);
  digitalWrite(entrada2, LOW);
  
  analogWrite(vel2, 0); // Motor da Direita
  digitalWrite(entrada3, LOW);
  digitalWrite(entrada4, LOW);
  delay(40);
}
// ================= Direção - Servo ==========================
void posimaquina(int angulo){
  maquina.write(angulo);
  delay(15);
}
