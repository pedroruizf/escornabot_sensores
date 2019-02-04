#include <escornabot.h>


escornabot mirobot;
boolean buzz = false;
int n;

void setup() {
  Serial.begin (9600);
}

void loop() {
  //prueba de bluetooth de librería

  switch (mirobot.blueT()) {//en función del caracter emitido por bluetooth hace varias acciones
    case 'A':
      mirobot.driveD (-10, 12);
      break;
    case 'R':
      mirobot.driveD (10, 12);
      break;
    case 'D':
      mirobot.turnA (45, 12);
      break;
    case 'I':
      mirobot.turnA (-45, 12);
      break;
    case 'C':
      mirobot.turnA (360, 12);
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
    case 'E':
      for (n = 1; n < 5; n++) {
        mirobot.driveD (-10, 12);
        mirobot.turnA (90, 12);
      }

  }

}
