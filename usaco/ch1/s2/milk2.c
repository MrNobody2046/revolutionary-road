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
        if(*(data[i] + strlen(data[i]) - 1)=='\n')
            *(data[i] + strlen(data[i]) - 1) = 0; //remove \n
        i ++;
    }
    return i;
}

int compare(int target[],int sample[]){
    return sample[0] - target[0];
}

void copy(int from[],int to[],int length){
    for(length --;length>=0;length--)
        to[length] = from[length];
}

void bisect(int data[],int trunk[][2],int length,int (*compare)(int [],int [])){
    // length is items contains in trunk, not the trunk size.
    int cond, high = length, low=0;
    int mid = high / 2;
    while(low < high){
        cond = compare(trunk[mid],data);
        if(cond > 0)
            low = mid + 1;
        else
            high = mid;
        mid = low + (high-low) / 2;
    }
    if(mid<length){
        int i=length;
        for(;i>mid;i--){
            copy(trunk[i-1],trunk[i],2);
        }
    }
    copy(data,trunk[mid],2);
}

void read_points(int ret[2],char c[]){
    int l = strlen(c);
    int i, j, k;
    i = j = k = 0;
    char temp[l];
    for(;i<=l;i++){
        if(c[i]!=' '&&c[i]!='\0')
            temp[k] = c[i], k++;
        else{
            temp[k++] = '\n';
            ret[j] = atoi(temp), j++;
            k = 0;
        }
    }
}

int record_max_work(int data[2],int current_max){
    int i;
    i = data[1] - data[0];
    if(i > current_max)
        return i;
    return current_max;
}

int record_max_idle(int big,int small,int current_max){
    int i;
    i = big - small;
    if(i > current_max)
        return i;
    return current_max;
}
    
int main(){
    char data[MAX_FARMER_NUM][MAX_LINE_LENGTH];
    int farmer_num,i;
    read_lines(data);
    farmer_num = atoi(data[0]);
    int data_points[farmer_num][2],temp[2];
    int (*comp)(int[],int[]) = compare;
    for(i=0;i<farmer_num;i++){
        read_points(temp,data[i+1]);
        bisect(temp, data_points, i, comp);
    }
    int section[2],j;
    int max_work_time, max_idle_time;
    max_idle_time = max_work_time = 0;
    for(i=0;i<farmer_num;i++){
        if(i!=0){
            if(data_points[i][0] > section[1]){ // open new section
                max_idle_time = record_max_idle(data_points[i][0], section[1], max_idle_time);
                copy(data_points[i],section,2);
                }
            else if(data_points[i][1] > section[1])  // extend section
                section[1] = data_points[i][1];
            max_work_time = record_max_work(section, max_work_time);
        }
        else{
            copy(data_points[i],section,2);
            max_work_time = record_max_work(section, max_work_time);
        }
    }
    FILE *fout;
    fout = fopen("milk2.out","w");
    char buffer[MAX_LINE_LENGTH];
    sprintf(buffer,"%d %d\n",max_work_time, max_idle_time);
    fputs(buffer,fout);
    exit(0);
}
