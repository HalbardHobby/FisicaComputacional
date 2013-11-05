#ifndef MASA_H
#define MASA_H
#include <math.h>

const float C_GRAV=4.52*pow(10,-4);
const float M_CENT=pow(10,12);

typedef struct {//define una masa en el espacio.
  int id;//el identificador númerico de la masa.
  //las posiciones en cada una de las coordenadas.
  float x;
  float y;
  //las velocidades de la masa en cada uno de los ejes.
  float vx;
  float vy;
} MASA;
#endif
