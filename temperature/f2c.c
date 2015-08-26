#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

double f2c(double temp){
  return (temp-32) * 5.0 / 9.0; 
}
#ifdef MAIN
int main(int arg, char **argv){
  double cel, fah;
  fah = 212;  cel = f2c(fah);
  assert( cel == 100);

  fah = 32;  cel = f2c(fah);
  assert( cel == 0);

  fah = -40;  cel = f2c(fah);
  assert( cel == -40);


  return 0;
}
#endif
