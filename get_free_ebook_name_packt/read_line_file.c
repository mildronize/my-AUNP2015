#include <stdio.h>
#include <stdlib.h>

int read_line_file(char *filename){
  FILE *fp;
  char buf[2048];
  int count = 0;
  fp = fopen(filename, "r");
  if ( fp == (FILE *)NULL){
    perror("fopen");
    exit(-1);
  }
  while(1){
    char *s = fgets( buf, sizeof(buf), fp);
    if ( s == (char*)NULL )break;
    // line 599 is the name of free ebook what we want
    if ( count == 599 )
      printf("%d: %s", count, buf);
    count++;
  }
  fclose(fp);
  return 0;
}

int main(int argc, char **argv){
  char *filename;
  filename = argv[1];
  read_line_file(filename);
  return 0;
}
