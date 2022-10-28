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
        tm=localtime(&t);
        if(tm==NULL){
            printf("Unexpected error occurred!\n");
        }
        char *day,*month;
        if(tm->tm_wday==0){
            day="Sunday";
        }
        else if(tm->tm_wday==1){
            day="Monday";
        }
        else if(tm->tm_wday==2){
            day="Tuesday";
        }
        else if(tm->tm_wday==3){
            day="Wednesday";
        }
        else if(tm->tm_wday==4){
            day="Thursday";
        }
        else if(tm->tm_wday==5){
            day="Friday";
        }
        else if(tm->tm_wday==6){
            day="Saturday";
        }
        if(tm->tm_mon==0) month="January";
        if(tm->tm_mon==1) month="February";
        if(tm->tm_mon==2) month="March";
        if(tm->tm_mon==3) month="April";
        if(tm->tm_mon==4) month="May";
        if(tm->tm_mon==5) month="June";
        if(tm->tm_mon==6) month="July";
        if(tm->tm_mon==7) month="August";
        if(tm->tm_mon==8) month="September";
        if(tm->tm_mon==9) month="October";
        if(tm->tm_mon==10) month="November";
        if(tm->tm_mon==11) month="December";

        printf("%s %d %s %d %02d:%02d:%02d %s\n",day,tm->tm_mday,month,tm->tm_year+1900,tm->tm_hour,tm->tm_min,tm->tm_sec,tzname[1]);

    }
}