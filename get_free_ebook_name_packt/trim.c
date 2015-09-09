#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

char* ltrim(char *str){
  while(isspace(*str)) str++;
  return str;
}

char* rtrim(char *str){
  int len, i;
  len = strlen(str);
  for( i = len-1; isspace(str[i]) ; i-- );
  str[i+1] = '\0';
  return str;
}

char* remove_end_string(char *str, char *str_rm){
  int len, lenrm;
  lenrm = strlen(str_rm);
  len = strlen(str);
  str[len-lenrm] = '\0';
  return str;
}

#ifdef MAIN
int main(int argc, char **argv){
  char buf[1024], res[1024], *ptr;
  char tag[]="</h2>";
  // Test ltrim
  strcpy(buf, "  ABC");
  assert( strcmp( buf, "  ABC") == 0 );
  ptr = ltrim(buf);
  assert( strcmp(ptr, "ABC") == 0 );

  strcpy(buf, "  \t \t  ABC");
  assert( strcmp( buf, "  \t \t  ABC") == 0 );
  ptr = ltrim(buf);
  printf("ltrim: %s\n", ptr);
  assert( strcmp(ptr, "ABC") == 0 );

  // Test rtrim
  strcpy(buf, "ABC  ");
  assert( strcmp( buf, "ABC  ") == 0 );
  ptr = rtrim(buf);
  printf("%s\n", ptr);
  assert( strcmp(ptr, "ABC") == 0 );

  // Test remove_end_string
  strcpy(buf, "ABC x</h2>");
  assert( strcmp( buf, "ABC x</h2>")  == 0 );

  ptr = remove_end_string(buf, tag);
  printf("%s\n", ptr);
  assert( strcmp(ptr, "ABC x") == 0 );



  return 0;
}
#endif
