#ifndef MASA_H
#define MASA_H
#include <math.h>

const float C_GRAV=4.46391*pow(10,-4); // En 10E10 masas solares, gigayears, kiloparsecs
const float M_CENT=100.0;//*pow(10,10); // En 10E10 masas solares 

typedef struct masa{//define una masa en el espacio.
  int id;//el identificador númerico de la masa.
  //las posiciones en cada una de las coordenadas.
  float x;
  float y;
  //las velocidades de la masa en cada uno de los ejes.
  float vx;
  float vy;
} MASA;
#endif
