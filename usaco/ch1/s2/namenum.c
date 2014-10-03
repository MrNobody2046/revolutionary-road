/*
ID:sphy1
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 16


void readline(FILE *f, char trunk[]){
    fgets(trunk,MAX_LINE_LENGTH,f);
    if(*(trunk+strlen(trunk)-1)==10){
        *(trunk+strlen(trunk)-1)=0;
        //remove \n
        }
}

int s2n(char s){
    if(s=='A'||s=='B'||s=='C')
        return 2;
    else if(s=='D'||s=='E'||s=='F')
        return 3;
    else if(s=='G'||s=='H'||s=='I')
        return 4;
    else if(s=='J'||s=='K'||s=='L')
        return 5;
    else if(s=='M'||s=='N'||s=='O')
        return 6;
    else if(s=='P'||s=='R'||s=='S')
        return 7;
    else if(s=='T'||s=='U'||s=='V')
        return 8;
    else if(s=='W'||s=='X'||s=='Y')
        return 9;
    else
        return 0;
}

int matching(char str[MAX_LINE_LENGTH],char ref[MAX_LINE_LENGTH]){
    int len = strlen(ref), i;
    if(len!=strlen(str))
        return 0;
    char temp[1];
    for(i=0;i<len;i++){
        temp[0] = ref[i];
        if(s2n(str[i])!=atoi(temp))
            break;
    }
    if(i==len)
        return 1;
    else
        return 0;
}

int main(){
    FILE *file, *fout;
    file = fopen("namenum.in","r");
    char input[MAX_LINE_LENGTH], temp[MAX_LINE_LENGTH];
    readline(file, input);
    fclose(file);
    printf("Input:%s\n",input);
    file = fopen("dict.txt","r");
    fout = fopen("namenum.out","w");
    int res,found=0;
    while(fgets(temp,MAX_LINE_LENGTH,file)){
        if(temp[strlen(temp)-1]=='\n')
            temp[strlen(temp)-1] = '\0';
        res = matching(temp,input);
        if(res==1){
            found++;
            printf("Find:%s\n",temp);
            temp[strlen(temp)] = '\n';
            fputs(temp, fout);
        }
    }
    if(found==0){
        fputs("NONE\n", fout);
    }
// TODO 在线上执行的时候偶尔会找不到

    exit(0);
}