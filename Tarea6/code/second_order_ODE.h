#ifndef SECOND_ORDER_ODE_H
#define SECOND_ORDER_ODE_H

#include <math.h>
#include "masa.h"

float func_prime_0(float t, float u_0, float u_1){
  return u_1;
}

float func_prime_1(float t, float u_0, float u_1){
  return (-C_GRAV*M_CENT)/(u_0*u_0);
}

float* RungeKuttaFourthOrderStep(float h, float t_old, float u_0_old, float u_1_old){
  
  /* Get K1 */
  float k1_0;
  float k1_1;

  k1_0 = func_prime_0(t_old, u_0_old, u_1_old);
  k1_1 = func_prime_1(t_old, u_0_old, u_1_old);


  /* Move to the middle of the interval using k1*/

  float t_middle_1;
  float u_0_middle_1;
  float u_1_middle_1;

  t_middle_1 = t_old + (h/2.0);
  u_0_middle_1 = u_0_old + (h/2.0) * k1_0;
  u_1_middle_1 = u_1_old + (h/2.0) * k1_1;

  
  /* Get K2 */
  
  float k2_0;
  float k2_1;

  k2_0 = func_prime_0(t_middle_1, u_0_middle_1, u_1_middle_1);
  k2_1 = func_prime_1(t_middle_1, u_0_middle_1, u_1_middle_1);


  /* Move to the middle of the interval using k2 */
  
  float t_middle_2;
  float u_0_middle_2;
  float u_1_middle_2;

  t_middle_2 = t_old + (h/2.0);
  u_0_middle_2 = u_0_old + (h/2.0) * k2_0;
  u_1_middle_2 = u_1_old + (h/2.0) * k2_1;


  /* Get k3 */

  float k3_0;
  float k3_1;

  k3_0 = func_prime_0(t_middle_2, u_0_middle_2, u_1_middle_2);
  k3_1 = func_prime_1(t_middle_2, u_0_middle_2, u_1_middle_2);

  /* Move at the end of the interval using k3 */
  
  float t_end;
  float u_0_end;
  float u_1_end;

  t_end = t_old + h;
  u_0_end = u_0_old + h*k3_0;
  u_1_end = u_1_old + h*k3_1;


  /* Get k4 */

  float k4_0 = func_prime_0(t_end, u_0_end, u_1_end);
  float k4_1 = func_prime_1(t_end, u_0_end, u_1_end);


  /* Get K_average */

  float k_average_0;
  float k_average_1;

  k_average_0 = (1.0/6.0) * (k1_0 + 2.0*k2_0 + 2.0*k3_0 + k4_0);
  k_average_1 = (1.0/6.0) * (k1_1 + 2.0*k2_1 + 2.0*k3_1 + k4_1);


  /* Get new t, u_0, u_1 */

  float t_new = t_old + h;
  float u_0_new = u_0_old + h*k_average_0;
  float u_1_new = u_1_old + h*k_average_1;

  float array_new[3];
  array_new[0] = t_new;
  array_new[1] = u_0_new;
  array_new[2] = u_1_new;

  return array_new;  
}
#endif
