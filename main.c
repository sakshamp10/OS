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

char** input_line(){
    char* inp= NULL;
    size_t size=0;
    getline(&inp,&size,stdin);
    int inp_length=10;
    char **words= malloc(inp_length*sizeof(char*));
    char *word = strtok(inp, " ");
    int i=0;
    while(word!=NULL){
        words[i]=word;
        if(++i>=inp_length){
            inp_length+=10;
            words=realloc(words,inp_length*sizeof(char*));
        }
        word = strtok(NULL," ");
    }
    words[i]=NULL;
    return words;
}

void echo(char** input){
    int k=1;
    int nflag=0;
    if(strcmp(input[1],"-n")==0){
        k++;
        nflag=1;
    }
    else if(strcmp(input[1],"-E")==0){
        k++;
    }
    for(int i=k;input[i]!=NULL;i++){

        //pid with $$ to be handled

        if(input[i+1]==NULL && nflag==1){
            char* temp=delim(input[i]);
            for(int j=0;temp[j]!='\0';j++){
                if(temp[j]!='\\')
                    printf("%c",temp[j]);
                else{
                    if(temp[j+1]=='\\'){
                        while(temp[j+1]=='\\'){
                            j++;
                        }
                        printf("%c",temp[j]);
                    }
                }
            }
            continue;
        }
        for(int j=0;input[i][j]!='\0';j++){
            if(input[i][j]!='\\')
                printf("%c",input[i][j]);
            else{
                if(input[i][j+1]=='\\'){
                    while(input[i][j+1]=='\\'){
                        j++;
                    }
                    printf("%c",input[i][j]);
                }
            }
        }
        if(input[i+1]!=NULL) printf(" ");
    }
}

void pwd(){
    size_t size=0;
    char *pwd=NULL;
    char* dir=getcwd(pwd,size);
    char p=0;
    while(dir[p]!='\0'){
        printf("%c",dir[p]);
        p++;
    }
    printf("\n");
}



void free2D(char** input){
    int i=0;
    while(input[i]!=NULL){
        free(input[i]);
        i++;
    }
    free(input);
}

int main(){
    while(1){
        char* a=NULL;
        size_t t=0;
        char* b= getcwd(a,t);
        printf("[%s]$ ",basename(b));
        free(a);
        free(b);
        char **input=input_line();
        char *inp=delim(input[0]);
        if(inp==NULL || input[0]==NULL){

        }
        else if(strcmp(inp,"cd")==0){
            char* inp2= delim(input[1]);
            if(inp2==NULL){
                if(chdir("root")!=0 && chdir("~")!=0){
                    printf("Error occurred!\n");
                }
            }
            else{
                if(chdir(inp2)!=0){
                    printf("Error occurred!\n");
                }
            }
        }
        else if(strcmp(inp,"echo")==0){
            echo(input);
        }
        else if(strcmp(inp,"pwd")==0){
            pwd();
        }
        else if(strcmp(inp,"exit")==0){
            break;
        }
        else if(strcmp(inp,"mkdir")==0){
//            pid_t proc;
//            proc=fork();
//            if(proc<0){
//                printf("Error occurred!\n");
//            }
//            else if(proc==0){
//                char* PATH=getenv(PATH);
//             execve("./mkdir.c",input,  );
//            }
//            else{
//                wait(NULL);
//            }
        }
        else if(strcmp(inp,"cat")==0){

        }
        else if(strcmp(inp,"date")==0){

        }
        else if(strcmp(inp,"rm")==0){

        }
        else if(strcmp(inp,"ls")==0){

        }
        else{
            printf("%s: Command not found\n",inp);
        }

//        free(inp);
//        free2D(input);
    }
    return 0;
}


