/*
ID:sphy1
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 32

void copy(int from[],int to[],int length){
    for(length --;length>=0;length--)
        to[length] = from[length];
}

void transform(int point[2],int ret[2],int size,int type){
    int temp[2];
    switch(type){
        case 1:{ // 90
        ret[0] = point[1], ret[1] = size - point[0] -1;
        break; }
        case 2:{ // 180
        ret[0] = size - point[0] -1, ret[1] = size - point[1] -1;
        break; }
        case 3:{ // 270
        ret[0] = size - point[1] -1, ret[1] = point[0];
        break; }
        case 4:{ // flip horizontal
        ret[0] = point[0]; ret[1] = size - point[1] - 1;
        break; }
        case 5:{ // flip horizontal + 90
        transform(point, temp, size, 4), transform(temp, ret, size, 1);
        break; }
        case 6:{ // flip horizontal + 180
        transform(point, temp, size, 4), transform(temp, ret, size, 2);
        break; }
        case 7:{ // flip horizontal + 270
        transform(point, temp, size, 4), transform(temp, ret, size, 3);
        break; }
        case 8:{ // not change
        ret[0] = point[0], ret[1] = point[1];
        break; }

    }
}

void printp(int point[2]){
    printf("<point:[%2d][%2d]>\n",point[0],point[1]);
}


int main(){
    FILE *fin,*fout;
    fin = fopen("transform.in","r");
    char temp[MAX_LINE_LENGTH];
    fgets(temp,MAX_LINE_LENGTH,fin);
    int size = atoi(temp),i,j,type;
    int orig[size][size];
    for(i=0;i<size;i++){
        fgets(temp,MAX_LINE_LENGTH,fin);
        for(j=0;j<size;j++){
            if(*(temp+j)=='-')
                orig[i][j] = 0;
            else
                orig[i][j] = 1;}
    }
    int changed[size][size];
    for(i=0;i<size;i++){
        fgets(temp,MAX_LINE_LENGTH,fin);
        for(j=0;j<size;j++){
            if(*(temp+j)=='-')
                changed[i][j] = 0;
            else
                changed[i][j] = 1;}
    }
    int op[2],tp[2],brk=0,passed=-1;
    for(type=1;type<9;type++){
        for(i=0;i<size;i++){
            if(brk==1)
                break;
            for(j=0;j<size;j++){
                op[0] = i,op[1] = j;
                transform(op,tp,size,type);
                printp(op),printp(tp);
                if(orig[i][j] != changed[tp[0]][tp[1]]){
                    brk = 1;
                    break; }
                }
            }
        if(brk==0){
            passed = type;
            break;}
        brk = 0;
    }
    if(passed>=5&&passed<=7)
        passed = 5;
    else if(passed==8)
        passed = 6;
    else if(passed==-1)
        passed = 7;
    else
    printf("Passed:%d",passed);
    fout = fopen("transform.out","w");
    sprintf(temp,"%d\n",passed);
    fputs(temp,fout);
    exit(0);
}
