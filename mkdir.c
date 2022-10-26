#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <libgen.h>

char* delim(char* input){
    char* inp=strtok(input,"\n");
    return inp;
}

void mkdir_p(){

}

void mkdir_v(char* argv[]){
    if(mkdir(argv[2])==0){
        printf("mkdir: created directory '%s'\n",argv[2]);
    }
    else{
        printf("Error occurred!\n");
    }
}

int main(int argc, char* argv[], const char* envp[]){
    printf("mkdir was called\n");
    if(argv[1][0]=='-'){
        if(argv[1][1]!='m' && argv[1][1]!='v'){
            printf("Invalid option!\n");
            return 0;
        }
        else if(argv[1][1]=='m'){
            mkdir_m();
        }
        else if(argv[1][1]=='v'){
            mkdir_v(argv);
        }
    }
    else{
        mkdir(delim(argv[1]));
    }
}