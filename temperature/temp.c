#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>

#include "temp.h"

int temp(double temp_in, char temp_in_unit, double *temp_out, char temp_out_unit){
  double tmp_var;
  if(temp_in_unit == 'c'){
    tmp_var = c2f(temp_in);
  }else if( temp_in_unit == 'f'){
    tmp_var = f2c(temp_in);
  }else {
    fprintf(stderr, "Temp unit '%c' is not supported yest\n", temp_in_unit);
    return -1;
  }
  printf("input = %.2lf %c, output = %.2lf %c\n", temp_in, temp_in_unit, tmp_var, temp_out_unit);
  *temp_out = tmp_var; 
  return 0; 
}

int main(int arg, char **argv){
  double temp_in, temp_out;
  char temp_in_unit, temp_out_unit;

  temp_in = 0; temp_in_unit = 'c'; temp_out_unit = 'f';
  temp(temp_in, temp_in_unit, &temp_out, temp_out_unit);
  assert( temp_out == 32);

  temp_in = 100; temp_in_unit = 'c'; temp_out_unit = 'f';
  temp(temp_in, temp_in_unit, &temp_out, temp_out_unit);
  assert( temp_out == 212);

  temp_in = -40; temp_in_unit = 'c'; temp_out_unit = 'f';
  temp(temp_in, temp_in_unit, &temp_out, temp_out_unit);
  assert( temp_out == -40 );

  temp_in = 32; temp_in_unit = 'f'; temp_out_unit = 'c';
  temp(temp_in, temp_in_unit, &temp_out, temp_out_unit);
  assert( temp_out == 0 );

  temp_in = 212; temp_in_unit = 'f'; temp_out_unit = 'c';
  temp(temp_in, temp_in_unit, &temp_out, temp_out_unit);
  assert( temp_out == 100 );

  temp_in = -40; temp_in_unit = 'f'; temp_out_unit = 'c';
  temp(temp_in, temp_in_unit, &temp_out, temp_out_unit);
  assert( temp_out == -40);



  return 0;
}
