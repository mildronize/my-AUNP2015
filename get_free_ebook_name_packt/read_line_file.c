#include <stdio.h>
#include <stdlib.h>
#include "packt.h"

char* read_line_file(char *filename ){
  FILE *fp;
  char *buf;
  int count = 0;
  fp = fopen(filename, "r");
  if ( fp == (FILE *)NULL){
    perror("fopen");
    exit(-1);
  }
  buf = (char*)malloc(sizeof(char)*2048);
  while(1){
    char *s = fgets( buf, sizeof(char)*2048, fp);
    /* char *s = fgets( buf, sizeof(buf), fp); */
    if ( s == (char*)NULL )break;
    // line 599 is the name of free ebook what we want
    if ( count == 599 ){
      /* out = buf; */
      /* printf("%d: %s\n\n", count, buf); */
      /* fclose(fp); */
      return buf;
    }
    count++;
  }
  fclose(fp);
  return NULL;
}

int main(int argc, char **argv){
  char *filename;
  char *out;
  filename = argv[1];
  out = read_line_file(filename);
  out = ltrim(out);
  out = rtrim(out);
  out = remove_end_string(out, "</h2>");
  out = rtrim(out);
  printf(">>>> %s\n", out);
  /* free(out); */
  return 0;
}
