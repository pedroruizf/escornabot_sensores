#include <escornabot.h>

escornabot mirobot;

const int echoPin = 12;
const int triggerPin = 11;
boolean funciona = false;

void setup() {
  //Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  //mirobot.stop();

  long distanciaD, distanciaI;//distancias para buscar a derechas e izquierdas

  compruebaBoton();

  if (funciona == true) {

    int cm = ping (triggerPin, echoPin);
    //compruebaBoton();
    //Serial.print("Distancia: ");
    //Serial.println(cm);

    if (cm <= 15) {
      mirobot.driveD(-5, 15);
      mirobot.stop();
      //cm = ping (triggerPin, echoPin);
      //compruebaBoton();
    }

    if (cm > 15) {
      mirobot.turnA (-45, 15);
      mirobot.stop();
      distanciaD = ping (triggerPin, echoPin);
      mirobot.turnA (90, 15);
      mirobot.stop();
      distanciaI = ping (triggerPin, echoPin);
      
      if (distanciaI < distanciaD) {
        mirobot.driveD(-5, 15);
        mirobot.stop();
   

      }
      else {
        mirobot.turnA(-90, 15);
        mirobot.stop();
        mirobot.driveD(-5, 15);
        mirobot.stop();
             

      }
      //cm = ping (triggerPin, echoPin);
      //compruebaBoton();
    }


  }


}


int ping(int triggerPin, int echoPin) {
  long duration, distanceCm;

  digitalWrite(triggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(triggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
  //delay (100);
}

void compruebaBoton () {
  if (mirobot.pushButton() == right) {
    funciona = !funciona;
    delay (300);
  }
}


