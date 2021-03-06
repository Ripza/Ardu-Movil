#include <NewPing.h>
//Pines de ultrasonido
const int pinecho = 10;
const int pintrigger = 9;

//Pines de motorreductor
//Motor izquierdo 4,5,2
//Motor derecho 6,7,3
int PinIN1 = 4;  
int PinIN2 = 5;  
int PinIN3 = 6;
int PinIN4 = 7;
//Pines controlar la velocidad
int ENB = 3; 
int ENA = 2;   

// VARIABLES PARA CALCULOS
unsigned int tiempo, distancia;
NewPing sonar(pintrigger, pinecho, 200);
void setup() {
  // inicializar la comunicación serial a 1000 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida

  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);

}
//Funcion para avanzar
void avanzar(int vela, int velb)
{
  analogWrite(ENA,vela);
  analogWrite(ENB,velb);
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  }

void detener()
{
    
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
}
void derecha(int vela, int velb)
{
  
  analogWrite(ENB,velb);
  analogWrite(ENA,vela);
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
}
void izquierda(int vela, int velb)
{
  analogWrite(ENA,vela);
    analogWrite(ENB,velb);
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
}

//calculo de la distancia para sensor
int ping(int pintrigger, int pinecho) {
  long duration, distanceCm;

  digitalWrite(pintrigger, LOW);  //para generar un pulso limpio ponemos a LOW 2us
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);  //generamos Trigger (disparo) de 2us
  delayMicroseconds(2);
  digitalWrite(pintrigger, LOW);

  duration = pulseIn(pinecho, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
}

//condiciones para que avance o se detenga segun la distancia del sensor

void loop() {
long distanceCm;
  distanceCm = sonar.ping_cm();  
  Serial.print("Ping: ");
  Serial.print(distanceCm); 
  Serial.println("cm");
  delay(25);
  int Limite = 30 ;                  // Medida en vacío del sensor

//si no cumple la distancia avanza o se detiene y dobla a la derecha
  
 if (distanceCm > Limite) {
     avanzar(130,130);  //minimo 130 al izquierdo, o no funciona el motor
  delay(200);
}
  
   else {
   detener();
   delay(1000);
   derecha(250,220);
   delay(400);
       if (distancia > Limite) {
       avanzar(130,130);
       delay(200);
      }
       else {
       detener();
       delay(1000);        
      }     
    }
    distanceCm = sonar.ping_median()/US_ROUNDTRIP_CM;  
    Serial.print("Ping: ");
    Serial.print(distanceCm); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
   }

