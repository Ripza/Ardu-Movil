#include <LEANTEC_ControlMotor.h>//Incluimos la librería control de motores 
#include <Ultrasonic.h> 


int PinIN1 = 4; //MOTOR Izquierdo HIGH 
int PinIN2 = 5; //MOTOR Izquierdo LOW
int PinIN3 = 6; //MOTOR Derecho LOW
int PinIN4 = 7; //MOTOR Derecho HIGH
int ENB = 3; // Velocidad motor B Derecho
int ENA = 2; // Velocidad motor A Izquierdo


//Pines de ultrasonido
const int pinecho = 10;
const int pintrigger = 9;

// Configuramos los pines que vamos a usar
ControlMotor control(PinIN2,PinIN1,PinIN3,PinIN4,ENA,ENB); // MotorDer1,MotorDer2,MotorIzq1,MotorIzq2,PWM_Derecho,PWM_Izquierdo

Ultrasonic sensor(9,10,30000); // (Trig PIN,Echo PIN, microsegundos max "distancia máxima") 30000us = 5 metros


int velocidad = 50;//Declaramos una variable para guardar la velocidad. 150 es la velocidad en la que empezará.

void setup() 
{ 
  // inicializar la comunicación serial a 1000 bits por segundo:
  Serial.begin(9600);
} 
 
void loop() 
{//Un motor gira en sentido horario y el otro antihorario
//Si estuvierán montados en un robot el robot avanzaria. 
 while(velocidad<254){
  
   velocidad++;
   control.Motor(180,1); 
   delay (200);
   chequear();
   }
velocidad=150;//Reseteamos la velocidad
}

 void girar_derecha(){
  control.Motor(200,-100);
  delay(1000);
 }
 void girar_izquierda(){
  control.Motor(200,100);
  delay(1000);
 }

 void retroceder(){
  control.Motor(-180,1);
  delay(1000);
 }
 void parar(){
  control.Motor(0,1);
  delay(1000);
 }
 void chequear(){
  long distanceCm;
  distanceCm = sensor.Ranging(CM);
  bool isStop = true;
  
  while(isStop){
    if(distanceCm < 25){
      parar();
    } else {
      isStop = false;
    }
    distanceCm = sensor.Ranging(CM);
  }
 }

