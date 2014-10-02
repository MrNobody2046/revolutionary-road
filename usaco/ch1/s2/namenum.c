/*
ID:sphy1
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 32




int main(){
    *FILE file;
    file = fopen("namenum.in","r");
    char temp[MAX_LINE_LENGTH];
    fgets(temp,MAX_LINE_LENGTH,file);
    int size = atoi(temp),i,j,type;


    exit(0);
}