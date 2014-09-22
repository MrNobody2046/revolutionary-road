/*
ID:sphy1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_YEAR 1900


struct year
{
    int *daynum;
    int fisrtday; // 0-6, represent the first day is which day of week
};


int isleapyear(int year){
    if((year%4==0&&year%100!=0)||(year%400==0))
        return 1;
    else
        return 0;
}


int main(){
    int norm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int i;
    struct year start;
    start.daynum = norm;
    start.fisrtday = 1;
    for(i=0;i<12;i++){
        printf("%d\n",*(start.daynum+i));
    }
    //printf("Isleap:%d",isleapyear(2004));

}