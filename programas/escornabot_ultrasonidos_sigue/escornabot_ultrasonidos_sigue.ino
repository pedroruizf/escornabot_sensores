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


  compruebaBoton();

  while (funciona == true) {

    int cm = ping (triggerPin, echoPin);
    //Serial.print("Distancia: ");
    //Serial.println(cm);

    while (cm <= 15) {
      mirobot.driveD(-1, 15);
      cm = ping (triggerPin, echoPin);
      compruebaBoton();
    }

    /*while (cm > 15) {
      int cm1 = ping (triggerPin, echoPin);
      mirobot.turnA (-10, 15);
      mirobot.driveD(-1,15);
      int cm2 = ping (triggerPin, echoPin);
      if (cm2 > cm1) {
        mirobot.turnA (10, 15);
        mirobot.driveD(-1,15);
      }
      compruebaBoton();
    }*/


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


