#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int c2f(int cel_temp){
  return cel_temp+32;
}

int main(int arg, char **argv){
  int cel, fah;

  cel = 0; fah = c2f(cel);
  assert( fah == 32 );

  cel = 100; fah = c2f(cel);
  assert( fah == 212 );

  return 0;
}
