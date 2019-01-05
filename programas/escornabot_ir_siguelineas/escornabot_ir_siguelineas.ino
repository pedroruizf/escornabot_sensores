#include <escornabot.h>

escornabot miescorni;

const int ir_izquierdo = 11;//izquierdo en sentido de los sensores mirando hacia delante
const int ir_derecho = 12;//derecho en sentido de los sensores mirando hacia delante
boolean funciona = false;

void setup() {
  //Serial.begin(9600);
  pinMode(ir_derecho, INPUT);
  pinMode(ir_izquierdo, INPUT);
}

void loop() {

  compruebaBoton();

  if (funciona == true) {

    if (digitalRead (ir_derecho) && !digitalRead (ir_izquierdo)) {//si sensor izquierdo encuentra blanco
      miescorni.turnA(-5, 10);//gira hacia la derecha en el sentido contrario a la marcha
    }
    if (!digitalRead (ir_derecho) && digitalRead (ir_izquierdo)) {//si sensor derecho encuentra blanco
      miescorni.turnA(5, 10);//gira hacia la izquierda en el sentido contrario a la marcha
    }

    if (digitalRead (ir_derecho) && digitalRead (ir_izquierdo)) {//si los dos sensores encuentran negro
      miescorni.driveD(-2, 13);//se mueve hacia delante en el sentido contrario a la marcha
    }
    if (!digitalRead (ir_derecho) && !digitalRead (ir_izquierdo)) {//si los dos sensores encuentran blanco
      miescorni.driveD(2, 13);//se mueve hacia detrás en el sentido contrario a la marcha
    }

  }

  else if (funciona == false) {
    miescorni.stop();
  }

}

void compruebaBoton () {
  if (miescorni.pushButton() == right) {
    funciona = !funciona;
    delay (300);
  }
}
