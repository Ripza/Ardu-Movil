
#include <NewPing.h>

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


//Ultrasonic sensor(9,10,500000); // (Trig PIN,Echo PIN, microsegundos max "distancia máxima") 30000us = 5 metros
NewPing sonar(pintrigger, pinecho, 200); // NewPing setup of pins and maximum distance.

void setup() {
  // inicializar la comunicación serial a 1000 bits por segundo:
  Serial.begin(9600);  
}

//condiciones para que avance o retroceda segun la distancia del sensor

void loop() {
  delay(100);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  }

