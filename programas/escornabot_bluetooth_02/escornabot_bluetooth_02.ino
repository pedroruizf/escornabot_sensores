#include <escornabot.h>

escornabot mirobot;
boolean buzz = false;

void setup() {
  Serial.begin (9600);
}

void loop() {
  //prueba de bluetooth de librería

  switch (mirobot.blueT()) {//en función del caracter emitido por bluetooth hace varias acciones
    case 'A':
      mirobot.driveD (10, 15);
      break;
    case 'R':
      mirobot.driveD (-10, 15);
      break;
    case 'D':
      mirobot.turnA (45, 15);
      break;
    case 'I':
      mirobot.turnA (-45, 15);
      break;
    case 'C':
      mirobot.turnA (360, 15);
      break;
    case '5':
      buzz = !buzz;
      if (buzz) {
        mirobot.buzzON();
      }
      else {
        mirobot.buzzOFF();
      }
      break;
      //default:
      // statements
  }

}




