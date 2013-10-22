#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

int main(float x_0, float y_0, float v_x_0, float v_y_0, float A){
  
  /** Definir los vectores de condiciones iniciales **/
  float x[120];
  float y[120];
  float v_x[120];
  float v_y[120];

  /** Definir los diferentes radios **/
  int r_1;
  int r_2;
  int r_3;
  int r_4;
  int r_5;

  float delta_ang_1;
  float delta_ang_2;
  float delta_ang_3;
  float delta_ang_4;
  float delta_ang_5;

  /** Crear el archivo donde se van escribir los resultados **/
  FILE *archivo;
  nombre = "condiciones_iniciales.txt"
  

  /** Escribir las condiciones iniciales para el centro de masa **/
  archivo = fopen(nombre, "w");
  fprintf("%f %f %f %f %f \n", -1, x_0, y_0, v_x, v_y); 
  fclose(archivo);

  /** Calcular y escribir las condiciones iniciales para las masas en la primer órbita **/ 
  r_1 = 10;
  delta_ang_1 = (2.0*PI) / 12.0;

  archivo = fopen(nombre, "w");
  
  for (int i=0, i<12, i++){
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

  fclose(archivo)


  



  

  


}
