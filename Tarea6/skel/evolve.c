#include <stdio.h>
#include <stdlib.h>
#include "masa.h"

void carga(char *filename);//carga la configuracion del choque.
void guardar(MASA *estrellas, char *filename);//guarda el estado pasado.
float func(float x, float y);//retorna la función;
void runge_kutta(MASA *estrella);//ejecuta runge kutta sobre los datos.

int main(int argc, char **argv){
  if(argc!=2){
    printf("Que pasa que no pasan las cosas como son!?");
    return -1;
  }
  return 0;
}
