#ifndef SECOND_ORDER_ODE_H
#define SECOND_ORDER_ODE_H

#include <math.h>
#include "masa.h"

float func_x_prime(float t, float x, float y, float vx, float vy, float x_cm, float y_cm){
  return vx;
}

float func_y_prime(float t, float x, float y, float vx, float vy, float x_cm, float y_cm){
  return vy;
}

float func_vx_prime(float t, float x, float y, float vx, float vy, float x_cm, float y_cm){
  return (-C_GRAV*M_CENT*abs(x-x_cm))/(pow(((x-x_cm)*(x-x_cm)+(y-y_cm)*(y-y_cm)),(3.0/2.0))); 
}

float func_vy_prime(float t, float x, float y, float vx, float vy, float x_cm, float y_cm){
    return (-C_GRAV*M_CENT*abs(y-y_cm))/(pow(((x-x_cm)*(x-x_cm)+(y-y_cm)*(y-y_cm)),(3.0/2.0))); 
}

float* RungeKuttaFourthOrderStep(float h, float t_old, float x_old, float y_old, float vx_old, float vy_old, float x_cm, float y_cm){
  
  /* Get K1 */
  float k1_x;
  float k1_y;
  float k1_vx;
  float k1_vy;

  k1_x = func_x_prime(t_old, x_old, y_old, vx_old, vy_old, x_cm, y_cm);
  k1_y = func_y_prime(t_old, x_old, y_old, vx_old, vy_old, x_cm, y_cm);
  k1_vx = func_vx_prime(t_old, x_old, y_old, vx_old, vy_old, x_cm, y_cm);
  k1_vy = func_vy_prime(t_old, x_old, y_old, vx_old, vy_old, x_cm, y_cm);



  /* Move to the middle of the interval using k1*/

  float t_middle_1;
  float x_middle_1;
  float y_middle_1;
  float vx_middle_1;
  float vy_middle_1;
 

  t_middle_1 = t_old + (h/2.0);
  x_middle_1 = x_old + (h/2.0) * k1_x;
  vx_middle_1 = vx_old + (h/2.0) * k1_vx;
  y_middle_1 = y_old + (h/2.0) * k1_y;
  vx_middle_1 = vy_old + (h/2.0) * k1_vy;

  
  /* Get K2 */
  
  float k2_x;
  float k2_y;
  float k2_vx;
  float k2_vy;

  k2_x = func_x_prime(t_middle_1, x_middle_1, y_middle_1, vx_middle_1, vy_middle_1, x_cm, y_cm);
  k2_y = func_y_prime(t_middle_1, x_middle_1, y_middle_1, vx_middle_1, vy_middle_1, x_cm, y_cm);
  k2_vx = func_vx_prime(t_middle_1, x_middle_1, y_middle_1, vx_middle_1, vy_middle_1, x_cm, y_cm);
  k2_vy = func_vy_prime(t_middle_1, x_middle_1, y_middle_1, vx_middle_1, vy_middle_1, x_cm, y_cm);

  /* Move to the middle of the interval using k2 */
  
  float t_middle_2;
  float x_middle_2;
  float y_middle_2;
  float vx_middle_2;
  float vy_middle_2;

  t_middle_2 = t_old + (h/2.0);
  x_middle_2 = x_old + (h/2.0) * k2_x;
  y_middle_2 = y_old + (h/2.0) * k2_y;
  vx_middle_2 = vx_old + (h/2.0) * k2_vx;
  vy_middle_2 = vy_old + (h/2.0) * k2_vy;


  /* Get k3 */

  float k3_x;
  float k3_y;
  float k3_vx;
  float k3_vy;

  k3_x = func_x_prime(t_middle_2, x_middle_2, y_middle_2, vx_middle_2, vy_middle_2, x_cm, y_cm);
  k3_y = func_y_prime(t_middle_2, x_middle_2, y_middle_2, vx_middle_2, vy_middle_2, x_cm, y_cm);
  k3_vx = func_vx_prime(t_middle_2, x_middle_2, y_middle_2, vx_middle_2, vy_middle_2, x_cm, y_cm);
  k3_vy = func_vy_prime(t_middle_2, x_middle_2, y_middle_2, vx_middle_2, vy_middle_2, x_cm, y_cm);

  /* Move at the end of the interval using k3 */
  
  float t_end;
  float x_end;
  float y_end;
  float vx_end;
  float vy_end;

  t_end = t_old + h;
  x_end = x_old + h*k3_x;
  y_end = y_old + h*k3_y;
  vx_end = vx_old +h*k3_vx;
  vy_end = vy_old +h*k3_vy;


  /* Get k4 */

  float k4_x = func_x_prime(t_end, x_end, y_end, vx_end, vy_end, x_cm, y_cm);
  float k4_y = func_y_prime(t_end, x_end, y_end, vx_end, vy_end, x_cm, y_cm);
  float k4_vx = func_vx_prime(t_end, x_end, y_end, vx_end, vy_end, x_cm, y_cm);
  float k4_vy = func_vy_prime(t_end, x_end, y_end, vx_end, vy_end, x_cm, y_cm);


  /* Get K_average */

  float k_average_x;
  float k_average_y;
  float k_average_vx;
  float k_average_vy;

  k_average_x = (1.0/6.0) * (k1_x + 2.0*k2_x + 2.0*k3_x + k4_x);
  k_average_y = (1.0/6.0) * (k1_y + 2.0*k2_y + 2.0*k3_y + k4_y);
  k_average_vx = (1.0/6.0) * (k1_vx + 2.0*k2_vx + 2.0*k3_vx + k4_vx);
  k_average_vy = (1.0/6.0) * (k1_vy + 2.0*k2_vy + 2.0*k3_vy + k4_vy);


  /* Get new t, u_0, u_1 */
  float *array_new=malloc(5*sizeof(float));
  array_new[0] = t_old + h;
  array_new[1] = x_old + h*k_average_x;
  array_new[2] = y_old + h*k_average_y;
  array_new[3] = vx_old + h*k_average_vx;
  array_new[4] = vy_old + h*k_average_vy;
  
  return array_new;  
}
#endif
