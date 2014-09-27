/*
ID:sphy1
LANG: C
TASK: friday
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

int readoffset(){
    int ret;
    FILE *fin;
    fin=fopen("friday.in","r");
    fscanf(fin,"%d",&ret);
    fclose(fin);
    return ret;
}

int daycount(struct year y){
    int i,count=0;
    for(i=0;i<12;i++){
        count += y.daynum[i];
    }
    return count;
}

void count13(struct year y,int res[]){
    int i,month_lastday;
    month_lastday = (y.fisrtday + 6) % 7;
    for(i=0;i<12;i++){
        //printf("%d,",(month_lastday + 13) % 7);
        res[(month_lastday + 13) % 7]++;
        month_lastday = (month_lastday + y.daynum[i]) % 7;
    }
    //printf("\n");
}

int main(){
    int norm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int res[] = {0,0,0,0,0,0,0};
    int i;
    int offset=readoffset();
    int lastday=6; // the week day of last year
    for(i=0;i<offset;i++){
        struct year temp;
        if(isleapyear(START_YEAR+i)==1){
            //printf("is leap %d\n",START_YEAR+i);
            temp.daynum = leap;
        }
        else
            temp.daynum = norm;
        temp.fisrtday = (lastday+1) % 7;
        //printf("%d\n",lastday);
        lastday = (lastday + daycount(temp)) % 7;
        count13(temp,res);

    }

    FILE *fout;
    char count[10];
    fout = fopen("friday.out","w");
    for(i=0;i<7;i++){
        sprintf(count,"%d",res[(i+12)%7]);
        fputs(count,fout);
        if ((i+12)%7!=4){
            fputs(" ",fout);
        }
        else
            fputs("\n",fout);
    }
    fclose(fout);
    exit(0);
//    printf("Isleap:%d",readoffset());
}