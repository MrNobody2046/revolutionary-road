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
        i ++;
    }
    return i;
}

int compare(int target[],int sample[]){
    return sample[0] - target[0];
}

void copy(int from[],int to[],int length){
    for(length --;length>=0;length--){
        to[length] = from[length];
    }
}

void bisect(int data[],int trunk[][2],int length,int (*compare)(int [],int [])){
    // length is items contains in trunk, not the trunk size.
    int high = length, low=0;
    int mid = high / 2;
    int cond;
    while(low < high){
        cond = compare(trunk[mid],data);
        printf("%d  %d ;%d\n",trunk[mid][0],data[0],cond);
        if(cond > 0)
            low = mid + 1;
        else
            high = mid;
        mid = low + (high-low) / 2;
    }
    printf("insert into[%d]\t%d:%d\n",mid,data[0],data[1]);
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
    int sorted[farmer_num][2],j;
    for(i=0,j=0;i<farmer_num;i++){
        //printf("work from:%d to %d\n",data_points[i][0],data_points[i][1]);
        if(i!=0){
            if(data_points[i][0] > sorted[j-1][1])
                copy(data_points[i],sorted[j],2),j++;
            else if(data_points[i][1]>sorted[j-1][1])
                    sorted[j-1][1] = data_points[i][1];
        }
        else{
            copy(data_points[i],sorted[i],2),j++;
        }
    }
    int work_time;
    int max_work_time=0;
    int idle[farmer_num],k=0;
    for(i=0;i<j;i++){
        //printf("handle from:%d to %d\n",sorted[i][0],sorted[i][1]);
        work_time = sorted[i][1] - sorted[i][0];
        if(work_time > max_work_time)
            max_work_time = work_time;
        if(i==0)
            idle[k] = sorted[i][1],k++;
        else{
            idle[k] = sorted[i][0],k++;
            idle[k] = sorted[i][1],k++;
        }
    }
    int idle_length = k;
    i = 0;
    int idle_time, max_idle_time;
    while(1){
        if(i>=k-1)
            break;
        idle_time = idle[i+1] - idle[i];
        if(idle_time > max_idle_time)
            max_idle_time = idle_time;
        i += 2;
    }
    FILE *fout;
    fout = fopen("milk2.out","w");
    char buffer[MAX_LINE_LENGTH];
    sprintf(buffer,"%d",max_work_time);
    fputs(buffer,fout);
    fputs(" ",fout);
    sprintf(buffer,"%d",max_idle_time);
    fputs(buffer,fout);
    fputs("\n",fout);
    exit(0);
}
