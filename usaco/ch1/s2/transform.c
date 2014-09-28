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
        case 0:{ // 90
        ret[0] = size - point[1] -1, ret[1] = point[0];
        break; }
        case 1:{ // 180
        ret[0] = size - point[0] - 1, ret[1] = size - point[1] - 1;
        break; }
        case 2:{ // 270
        ret[0] = point[1], ret[1] = size - point[0] - 1;
        break; }
        case 3:{ // flip horizontal
        ret[0] = point[0], ret[1] = size - point[1] - 1;
        break; }
        case 4:{ // flip horizontal + 90
        transform(point, temp, size, 3), transform(temp, ret, size, 0);
        break; }
        case 5:{ // flip horizontal + 180
        transform(point, temp, size, 3), transform(temp, ret, size, 1);
        break; }
        case 6:{ // flip horizontal + 270
        transform(point, temp, size, 3), transform(temp, ret, size, 2);
        break; }
    }
}

void printp(int point[2]){
    printf("<point:[%2d][%2d]>\n",point[0],point[1]);
}


int main(){
//    int p[]={1,1};
//    int ret[2];
//    transform(p,ret,5,0);
//    printp(ret);
//    transform(p,ret,5,1);
//    printp(ret);
//    transform(p,ret,5,2);
//    printp(ret);
//    transform(p,ret,5,3);
//    printp(ret);
//    transform(p,ret,5,4);
//    printp(ret);

    FILE *fin,fout;
    fin = fopen("transform.in","r");
    char temp[MAX_LINE_LENGTH];
    fgets(temp,MAX_LINE_LENGTH,fin);
    int size = atoi(temp),i,j,type;
    printf("size:%d",size);
    char orig[size][size];
    for(i=0;i<size;i++){
        fgets(temp,MAX_LINE_LENGTH,fin);
        *(temp+size * sizeof(char)) = '\0';
        strcpy(orig[i],temp);
    }
    char changed[size][size];
    for(i=0;i<size;i++){
        fgets(temp,MAX_LINE_LENGTH,fin);
        *(temp+size * sizeof(char)) = '\0';
        strcpy(changed[i],temp);
    }
    int op[2],tp[2],brk=0,passed=-1;
    for(type=0;type<7;type++){
        for(i=0;i<size;i++){
            if(brk==1)
                break;
            for(j=0;j<size;j++){
                op[0] = i,op[1] = j;
                transform(op,tp,size,type);
                printp(op),printp(tp);
                printf("Compare[%c] with [%c]\n",orig[i][j],changed[tp[0]][tp[1]]);
                if(orig[i][j] != changed[tp[0]][tp[1]]){
                    brk = 1;
                    printf("Break@type:%d",type);
                    break; }
                }
            }
        if(brk==1)
            brk =0;
        else{
            passed =type;
            break;
        }
    }
    printf("Passed:%d",passed);
    exit(0);
}
