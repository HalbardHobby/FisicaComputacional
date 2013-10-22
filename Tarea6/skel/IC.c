#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "masa.h"
#define PI 3.14159265358979323846

void init();//iniciliza el programa con las 100 masas
float calc_fuerza(float dist);//calcula la fuerza con base en la distancia 
+void configurar_masa(MASA *estrella, float velang);//configura la masa
+void movimiento(float vx, float vy);//cambia el movimiento de las estrellas con respecto al centro de masa
+void guardar(MASA *estrella, char *filename);//guarda la configuración del movimiento.

int main(int argc, char **argv){
  
  /** Definir el vector de condiciones iniciales **/
  MASA *galaxia=malloc(100*sizeof(MASA));

  /** Crear el archivo donde se van escribir los resultados **/
  FILE *archivo;
  string nombre = "condiciones_iniciales.txt";
  

  /** Escribir las condiciones iniciales para el centro de masa **/
  archivo = fopen(nombre, "w");
  fprintf("%f %f %f %f %f \n", -1, x_0, y_0, v_x, v_y); 
  fclose(archivo);

  /** Calcular y escribir las condiciones iniciales para las masas en la primer órbita **/ 
  r_1 = 10;
  delta_ang_1 = (2.0*PI) / 12.0;

  archivo = fopen(nombre, "w");
  
  for (int i=0, i<12, i+=1){
    x[i] = x_0 + r_1*cos(delta_ang_1*i);
    y[i] = y_0 + r_1*sin(delta_ang_1*i);
    v_x[i] = v_x_0 + sqrt(A/r_1)*cos(delta_ang_1*i);
    v_y[i] = v_y_0 + sqrt(A/r_1)*sin(delta_ang_1*i);

    fprintf("%f %f %f %f %f \n", i, x[i], y[i], v_x[i], v_y[i]);
  }

  fclose(archivo);


  /** Calcular y escribir las condiciones iniciales para las masas en la segunda órbita **/
  r_2 = 20;
  delta_ang_2 = (2.0*PI) / 18.0;

  archivo = fopen(nombre, "w");
  
  for (int i=12, i<30, i++){
    x[i] = x_0 + r_2*cos(delta_ang_2*(i-12));
    y[i] = y_0 + r_2*sin(delta_ang_2*(i-12));
    v_x[i] = v_x_0 + sqrt(A/r_1)*cos(delta_ang_2*(i-12));
    v_y[i] = v_y_0 + sqrt(A/r_1)*sin(delta_ang_2*(i-12));

    fprintf("%f %f %f %f %f \n", i, x[i], y[i], v_x[i], v_y[i]);
  }

  fclose(archivo);


  /** Calcular y escribir las condiciones iniciales para las masas en la tercera órbita **/
  r_3 = 30;
  delta_ang_3 = (2.0*PI) / 24.0;

  archivo = fopen(nombre, "w");
  
  for (int i=30, i<54, i++){
    x[i] = x_0 + r_3*cos(delta_ang_3*(i-30));
    y[i] = y_0 + r_3*sin(delta_ang_3*(i-30));
    v_x[i] = v_x_0 + sqrt(A/r_1)*cos(delta_ang_3*(i-30));
    v_y[i] = v_y_0 + sqrt(A/r_1)*sin(delta_ang_3*(i-30));

    fprintf("%f %f %f %f %f \n", i, x[i], y[i], v_x[i], v_y[i]);
  }

  fclose(archivo);


  /** Calcular y escribir las condiciones iniciales para las masas en la tercera órbita **/
  r_4 = 40;
  delta_ang_4 = (2.0*PI) / 30.0;

  archivo = fopen(nombre, "w");
  
  for (int i=54, i<84, i++){
    x[i] = x_0 + r_4*cos(delta_ang_4*(i-54));
    y[i] = y_0 + r_4*sin(delta_ang_4*(i-54));
    v_x[i] = v_x_0 + sqrt(A/r_1)*cos(delta_ang_4*(i-54));
    v_y[i] = v_y_0 + sqrt(A/r_1)*sin(delta_ang_4*(i-54));

    fprintf("%f %f %f %f %f \n", i, x[i], y[i], v_x[i], v_y[i]);
  }

  fclose(archivo);


  /** Calcular y escribir las condiciones iniciales para las masas en la tercera órbita **/
  r_5 = 50;
  delta_ang_5 = (2.0*PI) / 36.0;

  archivo = fopen(nombre, "w");
  
  for (int i=84, i<120, i++){
    x[i] = x_0 + r_5*cos(delta_ang_5*(i-84));
    y[i] = y_0 + r_5*sin(delta_ang_5*(i-84));
    v_x[i] = v_x_0 + sqrt(A/r_1)*cos(delta_ang_4*(i-84));
    v_y[i] = v_y_0 + sqrt(A/r_1)*sin(delta_ang_4*(i-84));

    fprintf("%f %f %f %f %f \n", i, x[i], y[i], v_x[i], v_y[i]);
  }

  fclose(archivo);

 return 0;
}
