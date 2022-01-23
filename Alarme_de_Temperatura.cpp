// Link da Simulação: https://www.tinkercad.com/things/5UQDhdoX1Ml
// Autoria: Gustavo Maciel e Mithras Santos
#include <LiquidCrystal.h>

//-----------------------------------------------
const byte buzzer = 1;
const byte TMP36 = 0; // Entrada analogica
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//--------------------------------------------------------

float temp = 0; // Temperatura 
int sensor = 0; // tempsensor

//--------------------------------------------------

void setup(){
    lcd.begin(16, 2);

    lcd.print("Temp: ");  
    analogRead(INTERNAL); //analogReference(INTERNAL1V1) - Mega
    /*
    Possui um incremento de 10 mV/oC: quando a temperatura aumenta em
    1oC, o sensor aumenta em 10 mV a tensão de saída
    */
    pinMode(buzzer, OUTPUT);
}

void loop(){	
    lcd.setCursor(0, 1);

    sensor = analogRead(TMP36);

    temp = (sensor * (0.1075268817)); //110 oC = 1100 mV = 1,1V -> valor digital 1023
    lcd.print(temp);

    if(temp > 30){ // Condicional temperatura apropriada
        digitalWrite(buzzer,HIGH);
    } else {
        digitalWrite(buzzer, LOW);
    }
}
 
