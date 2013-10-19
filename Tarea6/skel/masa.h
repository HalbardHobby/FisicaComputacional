#ifndef MASA_H
#define MASA_H
#include <math.h>

const double C_GRAV=4.52*pow(10,-30);
const double M_CENT=pow(10,12);

typedef struct masa{
  int id;//el identificador númerico de la masa.
  //las posiciones en cada una de las coordenadas.
  float x;
  float y;
  float z;
  //las velocidades de la masa en cada uno de los ejes.
  float vx;
  float vy;
  float vz;
} MASA;
#endif
