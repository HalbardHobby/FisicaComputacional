#include <stdio.h>
#include <stdlib.h>
#include "masa.h"
#include "second_order_ODE.h"

void init();//iniciliza el programa con las 100 masas
float calc_fuerza(float dist);//calcula la fuerza con base en la distancia 
void configurar_masa(MASA *estrella, float velang);//configura la masa
void movimiento(MASA *gal);//cambia el movimiento de las estrellas con respecto al centro de masa
void evolve(MASA *estrella);//calcula la posición de la estrella en la siguiente iteración.

void evolucion_una_galaxia(MASA *gal, int cont );
void evolucion_dos_galaxias(MASA *gal, int cont )


int main(int argc, char **argv){
  if(argc != 2){
    printf("Como conquistar la galaxia sin tener idea donde va?\n");
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


  //definiendo que hacer dependiendo del numero de masas
  if(cont==120){
    evolucion_una_galaxia(gal, cont);
  }
  else if (cont == 240){
    evolucion_dos_galaxias(gal, cont);
  }
  else{
    printf("no sé qué pasa!. \n");
  }
 
  
  
  return 0;
}


void evolucion_una_galaxia(MASA *gal, int cont ){

 //definiendo otro  arreglo de tipo MASA para guardar los datos del pasado inmediato
  MASA *gal_pas=malloc(cont*sizeof(MASA));

//definiendo variables necesarias para la integración
  float h = 0.001;
  int n_ite = (1.0+h)/h;
  float t = 0;
  float t_pas=0;
  float *nuevo_arreglo;
  int j;
  int k;

  //integrando para el primer giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;
    gal[0].x = gal_pas[0].x + (gal_pas[0].vx)*h;
    gal[0].y = gal_pas[0].y + (gal_pas[0].vy)*h;
    for(k=1;k<cont;k++){
      nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y);
      t = nuevo_arreglo[0];
      gal[k].x = nuevo_arreglo[1];
      gal[k].y = nuevo_arreglo[2];
      gal[k].vx = nuevo_arreglo[3];
      gal[k].vy = nuevo_arreglo[4];
    }
  }

  //imprimiendo en un archivo de texto los valores para el primer giga_año.
  FILE *salida;
  salida = fopen("../out/estado1.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);


//integrando para el segundo giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;
    gal[0].x = gal_pas[0].x + (gal_pas[0].vx)*h;
    gal[0].y = gal_pas[0].y + (gal_pas[0].vy)*h;
    for(k=1;k<cont;k++){
      nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y);
      t = nuevo_arreglo[0];
      gal[k].x = nuevo_arreglo[1];
      gal[k].y = nuevo_arreglo[2];
      gal[k].vx = nuevo_arreglo[3];
      gal[k].vy = nuevo_arreglo[4];
    }
  }

  //imprimiendo en un archivo de texto los valores para el segundo giga_año.
  salida = fopen("../out/estado2.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);


//integrando para el tercer giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;
    gal[0].x = gal_pas[0].x + (gal_pas[0].vx)*h;
    gal[0].y = gal_pas[0].y + (gal_pas[0].vy)*h;
    for(k=1;k<cont;k++){
      nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y);
      t = nuevo_arreglo[0];
      gal[k].x = nuevo_arreglo[1];
      gal[k].y = nuevo_arreglo[2];
      gal[k].vx = nuevo_arreglo[3];
      gal[k].vy = nuevo_arreglo[4];
    }
  }

  //imprimiendo en un archivo de texto los valores para el tercer giga_año.
  salida = fopen("../out/estado3.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);


//integrando para el cuarto giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;
    gal[0].x = gal_pas[0].x + (gal_pas[0].vx)*h;
    gal[0].y = gal_pas[0].y + (gal_pas[0].vy)*h;
    for(k=1;k<cont;k++){
      nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y);
      t = nuevo_arreglo[0];
      gal[k].x = nuevo_arreglo[1];
      gal[k].y = nuevo_arreglo[2];
      gal[k].vx = nuevo_arreglo[3];
      gal[k].vy = nuevo_arreglo[4];
    }
  }

  //imprimiendo en un archivo de texto los valores para el cuarto giga_año.
  salida = fopen("../out/estado4.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);


//integrando para el quinto giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;
    gal[0].x = gal_pas[0].x + (gal_pas[0].vx)*h;
    gal[0].y = gal_pas[0].y + (gal_pas[0].vy)*h;
    for(k=1;k<cont;k++){
      nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y);
      t = nuevo_arreglo[0];
      gal[k].x = nuevo_arreglo[1];
      gal[k].y = nuevo_arreglo[2];
      gal[k].vx = nuevo_arreglo[3];
      gal[k].vy = nuevo_arreglo[4];
    }
  }

  //imprimiendo en un archivo de texto los valores para el quinto giga_año.
  salida = fopen("../out/estado5.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);  
}


void evolucion_dos_galaxias(MASA *gal, int cont ){

 //definiendo otro  arreglo de tipo MASA para guardar los datos del pasado inmediato
  MASA *gal_pas=malloc(cont*sizeof(MASA));

//definiendo variables necesarias para la integración
  float h = 0.001;
  int n_ite = (1.0+h)/h;
  float t = 0;
  float t_pas=0;
  float *nuevo_arreglo;
  int j;
  int k;

  //integrando para el primer giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[0].x, gal_pas[0].y, gal_pas[0].vx, gal_pas[0].vy, gal_pas[120].x, gal_pas[120].y);
    gal[0].x = nuevo_arreglo[1];
    gal[0].y = nuevo_arreglo[2];
    gal[0].vx = nuevo_arreglo[3];
    gal[0].vy = nuevo_arreglo[4];

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[120].x, gal_pas[120].y, gal_pas[120].vx, gal_pas[120].vy, gal_pas[0].x, gal_pas[0].y);
    gal[120].x = nuevo_arreglo_2[1];
    gal[120].y = nuevo_arreglo_2[2];
    gal[120].vx = nuevo_arreglo_2[3];
    gal[120].vy = nuevo_arreglo_2[4];
    

    for(k=1;k<cont;k++){
      if(k!=120){
	nuevo_arreglo = RungeKuttaFourthOrderStep_2(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y, gal_pas[120].x, gal_pas[120].y);
	t = nuevo_arreglo[0];
	gal[k].x = nuevo_arreglo[1];
	gal[k].y = nuevo_arreglo[2];
	gal[k].vx = nuevo_arreglo[3];
	gal[k].vy = nuevo_arreglo[4];
      }
    }
  }

  //imprimiendo en un archivo de texto los valores para el primer giga_año.
  FILE *salida;
  salida = fopen("../out/2galaxias_estado1.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);


//integrando para el segundo giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[0].x, gal_pas[0].y, gal_pas[0].vx, gal_pas[0].vy, gal_pas[120].x, gal_pas[120].y);
    gal[0].x = nuevo_arreglo[1];
    gal[0].y = nuevo_arreglo[2];
    gal[0].vx = nuevo_arreglo[3];
    gal[0].vy = nuevo_arreglo[4];

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[120].x, gal_pas[120].y, gal_pas[120].vx, gal_pas[120].vy, gal_pas[0].x, gal_pas[0].y);
    gal[120].x = nuevo_arreglo_2[1];
    gal[120].y = nuevo_arreglo_2[2];
    gal[120].vx = nuevo_arreglo_2[3];
    gal[120].vy = nuevo_arreglo_2[4];

    for(k=1;k<cont;k++){
      if(k!=120){
	nuevo_arreglo = RungeKuttaFourthOrderStep_2(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y, gal_pas[120].x, gal_pas[120].y);
	t = nuevo_arreglo[0];
	gal[k].x = nuevo_arreglo[1];
	gal[k].y = nuevo_arreglo[2];
	gal[k].vx = nuevo_arreglo[3];
	gal[k].vy = nuevo_arreglo[4];
      }
    }
  }

  //imprimiendo en un archivo de texto los valores para el segundo giga_año.
  salida = fopen("../out/2galaxias_estado2.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);


//integrando para el tercer giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[0].x, gal_pas[0].y, gal_pas[0].vx, gal_pas[0].vy, gal_pas[120].x, gal_pas[120].y);
    gal[0].x = nuevo_arreglo[1];
    gal[0].y = nuevo_arreglo[2];
    gal[0].vx = nuevo_arreglo[3];
    gal[0].vy = nuevo_arreglo[4];

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[120].x, gal_pas[120].y, gal_pas[120].vx, gal_pas[120].vy, gal_pas[0].x, gal_pas[0].y);
    gal[120].x = nuevo_arreglo_2[1];
    gal[120].y = nuevo_arreglo_2[2];
    gal[120].vx = nuevo_arreglo_2[3];
    gal[120].vy = nuevo_arreglo_2[4];

    for(k=1;k<cont;k++){
      if(k!=120){
	nuevo_arreglo = RungeKuttaFourthOrderStep_2(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y, gal_pas[120].x, gal_pas[120].y);
	t = nuevo_arreglo[0];
	gal[k].x = nuevo_arreglo[1];
	gal[k].y = nuevo_arreglo[2];
	gal[k].vx = nuevo_arreglo[3];
	gal[k].vy = nuevo_arreglo[4];
      }
    }
  }

  //imprimiendo en un archivo de texto los valores para el tercer giga_año.
  salida = fopen("../out/2galaxias_estado3.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);


//integrando para el cuarto giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[0].x, gal_pas[0].y, gal_pas[0].vx, gal_pas[0].vy, gal_pas[120].x, gal_pas[120].y);
    gal[0].x = nuevo_arreglo[1];
    gal[0].y = nuevo_arreglo[2];
    gal[0].vx = nuevo_arreglo[3];
    gal[0].vy = nuevo_arreglo[4];

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[120].x, gal_pas[120].y, gal_pas[120].vx, gal_pas[120].vy, gal_pas[0].x, gal_pas[0].y);
    gal[120].x = nuevo_arreglo_2[1];
    gal[120].y = nuevo_arreglo_2[2];
    gal[120].vx = nuevo_arreglo_2[3];
    gal[120].vy = nuevo_arreglo_2[4];

    for(k=1;k<cont;k++){
      if(k!=120){
	nuevo_arreglo = RungeKuttaFourthOrderStep_2(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y, gal_pas[120].x, gal_pas[120].y);
	t = nuevo_arreglo[0];
	gal[k].x = nuevo_arreglo[1];
	gal[k].y = nuevo_arreglo[2];
	gal[k].vx = nuevo_arreglo[3];
	gal[k].vy = nuevo_arreglo[4];
      }
    }
  }

  //imprimiendo en un archivo de texto los valores para el cuarto giga_año.
  salida = fopen("../out/2galaxias_estado4.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);


//integrando para el quinto giga-año
  for(j=0;j<n_ite;j++){
    gal_pas = gal;
    t_pas = t;

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[0].x, gal_pas[0].y, gal_pas[0].vx, gal_pas[0].vy, gal_pas[120].x, gal_pas[120].y);
    gal[0].x = nuevo_arreglo[1];
    gal[0].y = nuevo_arreglo[2];
    gal[0].vx = nuevo_arreglo[3];
    gal[0].vy = nuevo_arreglo[4];

    nuevo_arreglo = RungeKuttaFourthOrderStep(h, t_pas, gal_pas[120].x, gal_pas[120].y, gal_pas[120].vx, gal_pas[120].vy, gal_pas[0].x, gal_pas[0].y);
    gal[120].x = nuevo_arreglo_2[1];
    gal[120].y = nuevo_arreglo_2[2];
    gal[120].vx = nuevo_arreglo_2[3];
    gal[120].vy = nuevo_arreglo_2[4];

    for(k=1;k<cont;k++){
      if(k!=120){
	nuevo_arreglo = RungeKuttaFourthOrderStep_2(h, t_pas, gal_pas[k].x, gal_pas[k].y, gal_pas[k].vx, gal_pas[k].vy, gal_pas[0].x, gal_pas[0].y, gal_pas[120].x, gal_pas[120].y);
	t = nuevo_arreglo[0];
	gal[k].x = nuevo_arreglo[1];
	gal[k].y = nuevo_arreglo[2];
	gal[k].vx = nuevo_arreglo[3];
	gal[k].vy = nuevo_arreglo[4];
      }
    }
  }

  //imprimiendo en un archivo de texto los valores para el quinto giga_año.
  salida = fopen("../out/2galaxias_estado5.txt", "w");
  for(i=0;i<cont;i++){
    fprintf(salida, "%d %f %f %f %f\n", gal[i].id, gal[i].x, gal[i].y, gal[i].vx, gal[i].vy);
  }
  fclose(salida);  
}
