#include<stdio.h>

struct info{
  char *name;
  int age;
  float height;
  float weight;

} n[] = {
  {"Smith", 100, 180.0, 90.5},
  {"John", 25, 150.9, 40.5},
};

int main(int argc, char **agrv){
  int i;
  for( i=0;i < 2;i++){
    printf("%s %3d %2.1f %2.2f\n", n[i].name, n[i].age, n[i].height, n[i].weight );
  }
  return 0;
}
