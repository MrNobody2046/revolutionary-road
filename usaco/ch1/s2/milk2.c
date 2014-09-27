/*
ID:sphy1
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 32
#define NAME "milk2.in"

#define MAX_FARMER_NUM 5000

int read_lines(char data[][MAX_LINE_LENGTH]){
    FILE *fin;
    fin = fopen(NAME,"r");
    int i = 0;
    while(fgets(data[i],MAX_LINE_LENGTH,fin)){
        if(*(data[i] + strlen(data[i]) - 1)=='\n'){
            *(data[i] + strlen(data[i]) - 1) = 0; //remove \n
            }
        printf("%s\n",data[i]);
        i ++;

    }
    return i;
}

void write_lines(){
    return;
}

int compare(int target[],int sample[]){
    return sample[0] - target[0];
}

void bisect(int data[],int trunk[][2],int length,int (*compare)(int [],int [])){
    // length is items contains in trunk, not the trunk size.
    int high = length, low=0;
    int mid = (high + low) / 2;
    int cond;
    while(low < high){
        cond = compare(trunk[mid], data);
        if(cond > 0)
            low = mid + 1;
        else if(cond < 0)
            high = mid;
        else
            break;
        mid = (high + mid) / 2;
    }
    trunk[mid][0] = data[0];
    trunk[mid][1] = data[1];
}

void read_points(int ret[2],char c[]){
    int l=strlen(c),start=-2,i;
    char b[l];
    for(i=0;i<l;i++){
        printf("%c",c[i]);
        if(start==-1)
            start=0;
        if(c[i]==' ')
            start ++;
            c[i] = '\0';
        if(start>=0)
            b[start] = c[i];
    }
    ret[0] = atoi(c);
    ret[1] = atoi(b);
    printf("from:%sto%s\n",c,b);
}
    


int main(){
    char data[MAX_FARMER_NUM][MAX_LINE_LENGTH];
    int farmer_num;
    read_lines(data);
    farmer_num = atoi(data[0]);
    printf("%d",farmer_num);
    int i;
    int data_points[farmer_num][2];
    int temp[2];
    int (*comp)(int[],int[]) = compare;
    for(i=0;i<farmer_num;i++){
        read_points(temp,data[i+1]);
        bisect(temp, data_points, i, comp);
    }
    exit(0);
}
