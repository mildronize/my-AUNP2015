#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>
#include<string.h>
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
void extract_input(char *input, double *temp, char *unit){
  int len;
  *temp = atoi(input);
  len = strlen(input);
  *unit = input[len-1];
}

int main(int argc, char **argv){
  double temp_in, temp_out;
  char temp_in_unit, temp_out_unit;
  char *input_str, target_format, tmp_unit;
  int i;
  /* printf("Num: %d\n", argc); */
  /* for( i=0; i< argc;i++){ */
    /* printf("> %s\n", argv[i]); */
  /* } */
  input_str = argv[1];
  temp_out_unit = argv[2][0];
  extract_input( input_str, &temp_in, &temp_in_unit);
  temp(temp_in, temp_in_unit, &temp_out, temp_out_unit);

  return 0;
}
