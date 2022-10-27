#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <libgen.h>

void cat_n(char* argv[]){
    FILE *file;
    int i=1;
    char* curr_file=argv[i];
    int count=1;
    while(curr_file!=NULL){
        if(curr_file[strlen(curr_file)-1]=='\n'){
            curr_file[strlen(curr_file)-1]='\0';
        }
        file= fopen(curr_file,"r");
        if(file==NULL){
            printf("cat: %s: No such file or directory!\n",curr_file);
        }
        else{
            char c=fgetc(file);
            printf("check_%d  ",count);
            count++;
            while(c!=EOF){
                if(c=='\n'){
                    printf("\ncheck2_%d  ",count);
                    count++;
                }
                printf("%c",c);
                c= fgetc(file);
            }
//            printf("%d  ",count);
//            count++;
        }
        i++;
        curr_file=argv[i];
    }
}

void cat_E(char* argv[]){

}


int main(int argc, char* argv[],char* envp[]){
    if(argv[1]==NULL || strcmp(argv[1]," ")==0|| strcmp(argv[1],"\n")==0){
        printf("Missing operand!\n");
        return 0;
    }
    if(argv[1][0]=='-'){
        if(argv[1][1]!='n' && argv[1][1]!='E'){
            printf("Invalid Options!\n");
            return 0;
        }
        else if(argv[1][1]=='n'){
            cat_n(argv);
        }
        else if(argv[1][1]=='E'){

        }
    }
    else{
        FILE *file;
        int i=1;
        char* curr_file=argv[i];
        while(curr_file!=NULL){
            if(curr_file[strlen(curr_file)-1]=='\n'){
                curr_file[strlen(curr_file)-1]='\0';
            }
            file= fopen(curr_file,"r");
            if(file==NULL){
                printf("cat: %s: No such file or directory!\n",curr_file);
            }
            else{
                char c=fgetc(file);
                while(c!=EOF){
                    printf("%c",c);
                    c= fgetc(file);
                }
            }
            i++;
            curr_file=argv[i];
        }
    }
}