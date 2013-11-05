#include <stdio.h>
#include <stdlib.h>
#include "masa.h"
#include "second_order_ODE.h"

void init();//iniciliza el programa con las 100 masas
float calc_fuerza(float dist);//calcula la fuerza con base en la distancia 
void configurar_masa(MASA *estrella, float velang);//configura la masa
void movimiento(MASA *gal);//cambia el movimiento de las estrellas con respecto al centro de masa
void evolve(MASA *estrella);//calcula la posición de la estrella en la siguiente iteración.

const int pos_c1=0;
const int pos_c2=120;

int main(int argc, char **argv){
  if(argc != 2){
    printf("Como conquistar la galaxia sin tener idea donde va?");
    return -1;
  }

  //contando las lineas del archivo
  FILE *mapa=fopen(argv[1],"r");
  if(mapa==0){//mirando que el archivo este bien.
    printf("Algo malo ocurrio.\n");
    return -1;
  }
  char c=0;
  int cont=0;
  while(c!=EOF){
    c=fgetc(mapa);
    if(c=='\n')
      cont++;
  }

  //cargando el archivo
  fclose(mapa);
  mapa=fopen(argv[1],"r");
  MASA *gal=malloc(cont*sizeof(MASA));
  int i =0;
  for(i;i<cont;i++)
    fscanf(mapa, "%d %f %f %f %f", &gal[i].id, &gal[i].x, &gal[i].y, &gal[i].vx, &gal[i].vy);

  return 0;
}
