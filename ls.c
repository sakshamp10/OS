#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <libgen.h>


int main(){
    char* l="/mkdir.c";
    char* p="path/to/dest";
    p=strcat(p,l);
    printf("%s\n",p);
    return 0;
}