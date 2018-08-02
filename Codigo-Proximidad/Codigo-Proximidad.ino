
#include <Ultrasonic.h> 

//Pines de ultrasonido
const int pinecho = 10;
const int pintrigger = 9;
//Pines de motorreductor

int PinIN1 = 4;
int PinIN2 = 5;
int PinIN3 = 6;
int PinIN4 = 7;
int ENB = 3; // ENB conectada al pin 3 de Arduino
int ENA = 2;
// VARIABLES PARA CALCULOS
unsigned int tiempo, distancia;


Ultrasonic sensor(9,10,30000); // (Trig PIN,Echo PIN, microsegundos max "distancia máxima") 30000us = 5 metros


void setup() {
  // inicializar la comunicación serial a 1000 bits por segundo:
  Serial.begin(9600);
  
}

//calculo de la distancia para sensor
int ping(int pintrigger, int pinecho) {
  long duration, distanceCm;

  distanceCm =sensor.Ranging(CM);
  
  Serial.println(distanceCm);
  
  return distanceCm;
}

//condiciones para que avance o retroceda segun la distancia del sensor

void loop() {
  long duracion, distancia ;
  int cm = sensor.Ranging(CM);
  Serial.print("Distancia: ");
  Serial.println(cm);
  delay(1000);
  int Limite = 30 ;                  // Medida en vacío del sensor

  }

