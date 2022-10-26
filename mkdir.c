#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <libgen.h>

void mkdir_m(){}
void mkdir_v(){}

int main(int argc, char* argv[], const char* envp[]){
    if(argv[1][0]=='-'){
        if(argv[1][1]!='m' && argv[1][1]!='v'){
            printf("Invalid option!\n");
            return 0;
        }
        else if(argv[1][1]=='m'){
            mkdir_m();
        }
        else if(argv[1][1]=='v'){
            mkdir_v();
        }
    }
    else{
        for(int i=0;argv[i]!=NULL;i++){

        }
    }
}