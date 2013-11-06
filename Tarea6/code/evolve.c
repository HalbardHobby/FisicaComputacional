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
    fscanf(mapa, "%d %f %f %f %f %f", &gal[i].id, &gal[i].x, &gal[i].y, &gal[i].vx, &gal[i].vy);

  //definiendo otro  arreglo de tipo MASA para guardar los datos del pasado inmediato
  MASA *gal_pas=malloc(cont*sizeof(MASA));
 
  //definiendo variables necesarias para la integración
  float h = 0.001;
  float n_ite = int((1.0+h)/h);
  float t = 0;
  float t_pas=0;
  float nuevo_arreglo[5];
  float x_cm;
  float y_cm;

  //integrando para el primer giga-año
  int j;
  int k;
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;
    for(k=0;k<cont;k++){
      nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, &gal_pas[k].x, &gal_pas[k].y, &gal_pas[k].vx, &gal_pas[k].vy, &gal_pas[0].x, &gal_pas[0].y);
      t = nuevo_arreglo[0];
      &gal[k].x = nuevo_arreglo[1];
      &gal[k].y = nuevo_arreglo[2];
      &gal[k].vx = nuevo_arreglo[3];
      &gal[k].vy = nuevo_arreglo[4];
    }
  }

  //imprimiendo en un archivo de texto los valores para el primer giga_año.
  FILE *salida;
  salida = fopen("condiciones_primer_gigayear.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f %f", &gal[i].id, &gal[i].x, &gal[i].y, &gal[i].vx, &gal[i].vy);
  }
  fclose(salida);


  
  return 0;
}



  //integrando para el primer giga-año.
  
