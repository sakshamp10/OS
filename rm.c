#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>

void rm_prompt(char* argv[]){
    int flag=0;
    DIR *dir=opendir(".");
    struct stat st;
    struct dirent *directory;
    directory= readdir(dir);
    while(directory!=NULL){
        if(argv[2][strlen(argv[2])-1]=='\n'){
            argv[2][strlen(argv[2])-1]='\0';
        }
        if(strcmp(directory->d_name,argv[2])==0){
            stat(directory->d_name,&st);
            if(S_ISDIR(st.st_mode)!=0){
                printf("Cannot delete a directory!\n");
                return;
            }
            printf("Do you want to remove the file: '%s'?[y/n] ",argv[2]);
            char c;
            scanf("%c",&c);
            if(c=='y' || c=='Y'){
                if(!remove(directory->d_name)){
                    flag=1;
                    break;
                }
            }
        }
        directory=readdir(dir);
    }
    if(flag==0){
        printf("File not found!\n");
        return;
    }
}


void rm_verbose(char* argv[]){
    int flag=0;
    DIR *dir=opendir(".");
    struct stat st;
    struct dirent *directory;
    directory= readdir(dir);
    while(directory!=NULL){
        if(argv[2][strlen(argv[2])-1]=='\n'){
            argv[2][strlen(argv[2])-1]='\0';
        }
        if(strcmp(directory->d_name,argv[2])==0){
            stat(directory->d_name,&st);
            if(S_ISDIR(st.st_mode)!=0){
                printf("Cannot delete a directory!\n");
                return;
            }
            if(!remove(directory->d_name)){
                flag=1;
                break;
            }
        }
        directory=readdir(dir);
    }
    if(flag==0){
        printf("File not found!\n");
        return;
    }
    else{
        printf("removed: %s\n",argv[1]);
    }
}

int main(int argc, char* argv[],char* envp[]){
    if(argv[1]==NULL || strcmp(argv[1],"\n")==0 || strcmp(argv[1]," ")==0){
        printf("Expected arguments not found!\n");
        return 0;
    }
    if(strcmp(argv[1][0],"-")==0){
        if(argv[1][1]!='v' && argv[1][1]!='i'){
            printf("Invalid Option!\n");
            return 0;
        }
    }
    else if(strcmp(argv[1],"-i")==0){
        rm_prompt(argv);
    }
    else if(strcmp(argv[1],"-v")==0){
        rm_verbose(argv);
    }
    else{
        int flag=0;
        DIR *dir=opendir(".");
        struct stat st;
        struct dirent *directory;
        directory= readdir(dir);
        while(directory!=NULL){
            if(argv[1][strlen(argv[1])-1]=='\n'){
                argv[1][strlen(argv[1])-1]='\0';
            }
            if(strcmp(directory->d_name,argv[1])==0){
                stat(directory->d_name,&st);
                if(S_ISDIR(st.st_mode)!=0){
                    printf("Cannot delete a directory!\n");
                    return 0;
                }
                if(!remove(directory->d_name)){
                    flag=1;
                    break;
                }
            }
            directory=readdir(dir);
        }
        if(flag==0){
            printf("File not found!\n");
            return 0;
        }
    }
}