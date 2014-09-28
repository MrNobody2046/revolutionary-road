/*
ID:sphy1
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("<point:%2d ,%2d >\n",point[0],point[1]);
}

int main(){
    int p[]={1,1};
    int ret[2];
    transform(p,ret,5,0);
    printp(ret);
    transform(p,ret,5,1);
    printp(ret);
    transform(p,ret,5,2);
    printp(ret);
    transform(p,ret,5,3);
    printp(ret);
    transform(p,ret,5,4);
    printp(ret);
    exit(0);
}
