#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define HOME "/home/thada"
#define FILENAMECOUNT HOME "/tmp/count-tmp.txt"
#define FILENAMEDATE HOME "/tmp/date-tmp.txt"
#define FILENAMETARGET HOME "/tmp/count.txt"

#define CMD "who | cut -f1 -d' ' | wc -l > " FILENAMECOUNT
#define CMDDATE "date > " FILENAMEDATE

char *datestr(){
    FILE *f;
    static char tmp [80];

    system(CMDDATE);
    f = fopen(FILENAMEDATE , "r");
    if (f == (FILE*)NULL ) { perror("fopen"); exit(-1); }
    fgets(tmp, sizeof(tmp) , f);
    tmp[strlen(tmp)-1] = '\0';
    fclose(f);
    return tmp;
}

int count_user(){
    FILE *f;
    int count;
    system(CMD);

    f = fopen(FILENAMECOUNT , "r");
    if (f == (FILE*)NULL ) { perror("fopen"); exit(-1); }
    fscanf(f, "%d", &count);
    fclose(f);
    return count;
}

int save2file(char *buf){
    FILE *f;
    f = fopen(FILENAMETARGET , "a");
    if (f == (FILE*)NULL ) { perror("fopen"); exit(-1); }
    fprintf(f, "%s\n", buf);
    fclose(f);
    return 0;
}
int logdaemon(){
    char *date;
    int count;
    static char buf[100];
    while (1) {
        date = datestr();
        count = count_user();
        sprintf(buf, "%s %d", date, count);
        save2file(buf);
        sleep(1);
    }
    return 0;
}

int main(){
    int pid;

    pid=fork();
    if(pid== -1 ) { perror("fork"); exit(-1);}
    if(pid == 0 )
       logdaemon();
    else
        printf("Child process id = %d\n", pid);
    return 0;
}


