#include <stdio.h>
#include <stdlib.h>

// include lib for stat()
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <sys/time.h> //gettimeofday()
#include <time.h> //ctime()

#include "packt.h"

char* get_book_name(char* filename){
  char* out;
  out = read_line_file(filename);
  out = ltrim(out);
  out = rtrim(out);
  out = remove_end_string(out, "</h2>");
  out = rtrim(out);
  out = ltrim(out);
  return out;
}

int main(int argc, char **argv){
  struct stat buf;
  struct timeval tv;
  char *filename;
  FILE *fp;
  /* struct timezone tz; */
  filename = argv[1];
  gettimeofday(&tv, NULL);
  /* printf("time of day = %ld . %ld\n", tv.tv_sec, tv.tv_usec); */
  printf("current time of day = %s\n", ctime(&tv.tv_sec));
  if ( !stat(filename, &buf) ){
    fp = fopen("book-list.txt", "a");
    fprintf(fp,"%s %s\n", ctime(&buf.st_mtime), get_book_name(filename));
      /* printf("ctime of file %s = %s\n", filename, ctime(&buf.st_mtime)); // get modify time of the file */
  }else {
    perror("stat");
    exit(-1);
  }

  /* printf("ctime = %ld, mtime = %ld, atime = %ld\n", buf.st_ctime, buf.st_mtime, buf.st_atime); */
  /* return system("curl -s https://www.packtpub.com/packt/offers/free-learning > out.txt"); */
  return 0;

}
