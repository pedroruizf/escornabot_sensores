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

  if (funciona == true) {
    int cm = ping (triggerPin, echoPin);
    //Serial.print("Distancia: ");
    //Serial.println(cm);



    if (cm > 15) {
      mirobot.driveD(-5, 15);
      compruebaBoton();
    }
    else if (cm <= 15) {

      mirobot.turnA (-45, 15);
      mirobot.driveD (5, 15);
      compruebaBoton();
    }


  }

  else if (funciona == false) {
    mirobot.stop();
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


