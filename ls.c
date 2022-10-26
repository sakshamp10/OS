#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <libgen.h>


int main(){
    char l[100]="/mkdir.c";
    char p[100]="path/to/dest";
    strcat(p,l);
    printf("%s\n",p);
    return 0;
}