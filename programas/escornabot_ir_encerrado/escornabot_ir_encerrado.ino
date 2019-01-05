#include <escornabot.h>

escornabot mirobot;

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

    if (digitalRead (ir_derecho) && !digitalRead (ir_izquierdo)) {//si sólo sensor derecho encuentra línea negra
      mirobot.turnA(90, 10);//gira hacia izquierda en el sentido contrario a la marcha 
    }
    if (!digitalRead (ir_derecho) && digitalRead (ir_izquierdo)) {//si sólo sensor izquierdo encuentra línea negra
      mirobot.turnA(-90, 10);//gira hacia derecha en el sentido contrario a la marcha 
    }

    if (digitalRead (ir_derecho) && digitalRead (ir_izquierdo)) {//si los dos sensores encuentran línea negra
      mirobot.driveD(2, 13);//da marcha atrás en el sentido contrario a la marcha
    }
    if (!digitalRead (ir_derecho) && !digitalRead (ir_izquierdo)) {//si los dos sensores no encuentran línea negra
      mirobot.driveD(-2, 13);//va hacia delante en el sentido contrario a la marcha
    }
    
  }

  else if (funciona == false) {
    mirobot.stop();
  }

}

void compruebaBoton () {
  if (mirobot.pushButton() == right) {
    funciona = !funciona;
    delay (300);
  }
}
