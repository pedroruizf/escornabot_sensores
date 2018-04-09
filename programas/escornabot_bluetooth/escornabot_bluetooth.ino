#include <escornabot.h>

escornabot mirobot;
boolean buzz=false;

void setup() {
  Serial.begin (9600);
}

void loop() {
  //prueba de bluetooth de librería

    switch (mirobot.blueT()) {//en función del caracter emitido por bluetooth hace varias acciones
    case 'A':
      mirobot.drive (0.25, 12);
      break;
    case 'R':
      mirobot.drive (-0.25, 12);
      break;
    case 'D':
      mirobot.turn (0.125, 12);
      break;
    case 'I':
      mirobot.turn (-0.125, 12);
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




