#include <stdio.h>
#include <stdlib.h>
#include "masa.h"

void init();//iniciliza el programa con las 100 masas
float calc_fuerza(float dist);//calcula la fuerza con base en la distancia 
void configurar masa(MASA *estrella, float velang);//configura la masa
void movimiento();//cambia el movimiento de las estrellas con respecto al centro de masa

int main(int argc, char **argv){
  if(argc != 5){
    printf("Como conquistar la galaxia sin tener idea donde va?");
    return -1;
  }
  printf("%lf %lf\n", C_GRAV, M_CENT );
  return 0;
}

void carga(char *filename);//carga la configuracion del choque.
void guardar(MASA *estrellas, char *filename);//guarda el estado pasado.
<<<<<<< HEAD
float func(float x, float y);//retorna la función;
void runge_kutta(MASA *estrella);//ejecuta runge kutta sobre los datos.

int main(int argc, char **argv){
  if(argc!=2){
    printf("Que pasa que no pasan las cosas como son!?");
    return -1;
  }
  return 0;
}
=======

>>>>>>> de543fe9952800e5df34a9b5373d639aecf16fcd
