#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

void ls_a(char* argv[]){

}

void ls_l(char* argv[]){

}

int main(int argc, char* argv[],char* envp[]){
    if(argv[1]==NULL || strcmp(argv[1],"\n")==0 || strcmp(argv[1]," ")==0){
        printf("No argument found for file name!\n");
        return 0;
    }
    if(argv[1]!=NULL && strcmp(argv[1][0],'-')==0){
        if(argv[1][1]!="a" && argv[1][1]!="l"){
            printf("Invalid Options!\n");
            return 0;
        }
        else if(argv[1][1]=='a'){
            ls_a(argv);
        }
        else if(argv[1][1]=='l'){
            ls_l(argv);
        }
    }
    else{
        DIR *dir = opendir(argv[1]);
        struct dirent *directory;
        if(dir==0){
            printf("Error occurred in opening or reading the directory contents!\n");
            return 0;
        }
        directory= readdir(dir);
        while(directory!=NULL){
            if(directory->d_name[0]!='.'){
                printf("%s ",directory->d_name);
            }
            directory= readdir(dir);
        }
        printf("\n");
    }
}