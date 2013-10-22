#include <stdio.h>
#include <stdlib.h>
#include "masa.h"

void init();//iniciliza el programa con las 100 masas
float calc_fuerza(float dist);//calcula la fuerza con base en la distancia 
void configurar_masa(MASA *estrella, float velang);//configura la masa
void movimiento(float vx, float vy);//cambia el movimiento de las estrellas con respecto al centro de masa
void guardar(MASA *estrella, char *filename);//guarda la configuración del movimiento.

int main(int argc, char **argv){
  if(argc != 5){
    printf("Como conquistar la galaxia sin tener idea donde va?");
    return -1;
  }
  return 0;
}
