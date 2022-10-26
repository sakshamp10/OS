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

void mkdir_p(char* argv[]){
    if(argv[2]==NULL || strcmp(argv[2],"\n")==0 || strcmp(argv[2]," ")==0){
        printf("Expected file name: not found!\n");
        return;
    }
    char* curr_dir=NULL;
    size_t s=0;
    curr_dir = getcwd(curr_dir,s);
    printf("%s\n",argv[2]);
    char* file = strtok(argv[2],"/");
    printf("file: %s\n",file);
    while(file!=NULL){
        if(mkdir(delim(file))!=0){
            printf("Error in creating the specified directory!: %s\n",file);
            return;
        }
        chdir(delim(file));
        file=strtok(NULL,"/");
        printf("%d\n",(file==NULL));
        printf("%s\n",file);
    }
//    files[count]=NULL;
//    printf(" last: %s",files[count]);
//    int i=0;
//    while(files[i]!=NULL){
//        file=files[i];
//        if(mkdir(delim(file))!=0){
//            printf("Error in creating the specified directory!: %s\n",delim(file));
//            return;
//        }
//        printf("made: %s\n",file);
//        i++;
//        chdir(delim(file));
//
//    }
    printf("123\n");
    chdir(delim(curr_dir));
    return;
}

void mkdir_v(char* argv[]){
    if(argv[2]==NULL || strcmp(argv[2],"\n")==0 || strcmp(argv[2]," ")==0){
        printf("Expected file name: not found!\n");
        return;
    }
    char* file=delim(argv[2]);
    if(mkdir(file)==0){
        printf("mkdir: created directory '%s'\n",file);
    }
    else{
        printf("Error occurred!\n");
    }
}

int main(int argc, char* argv[], const char* envp[]){
//    printf("mkdir was called\n");
    if(argv[1]!=NULL && argv[1][0]=='-'){
        if(argv[1][1]!='p' && argv[1][1]!='v'){
            printf("Invalid option!\n");
            return 0;
        }
        else if(argv[1][1]=='p'){
            mkdir_p(argv);
        }
        else if(argv[1][1]=='v'){
            mkdir_v(argv);
        }
    }
    else{
        if(argv[1]==NULL || strcmp(argv[1],"\n")==0 || strcmp(argv[1]," ")==0){
            printf("Expected file name: not found!\n");
            return 0;
        }
        if(mkdir(delim(argv[1]))!=0){
            printf("Could not create directory due to unexpected error!\n");
        }
    }
}