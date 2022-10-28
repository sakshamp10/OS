#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <sys/wait.h>
#include <libgen.h>
#include <time.h>


int main(int argc, char* argv[],char* envp[]){
    if(argv[1]==NULL || strcmp(argv[1],"\n")==0 || strcmp(argv[1]," ")==0){
        struct tm *tm;
        time_t t= time(NULL);
        tm= localtime(&t);
        printf("CURRENT DATE AND TIME: %s\n", asctime(tm));
    }
}