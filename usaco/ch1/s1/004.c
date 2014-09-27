/*
ID:sphy1
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAIN_LENGTH 512


void readline(FILE *f, char trunk[]){
    fgets(trunk,MAX_CHAIN_LENGTH,f);
    if(*(trunk+strlen(trunk)-1)==10){
        *(trunk+strlen(trunk)-1)=0;
        //remove \n
        }
}

void partion(char trunk[], int res[], int index, int length){
    // start to end is half closed interval  ->> [start,end) then trunk[end] is another journey
    int start;
    start = index + length;
    char flag, temp;
    flag = trunk[start % length];
    int j=0;
    while(j < length){
        j ++;
        start --;
        temp = trunk[start % length];
        if(temp != flag && temp != 'w'){
            if(flag != 'w'){
                break;
            }
            else
                flag = temp;
        }
    };
    if(j==length){
        res[0] = res[1] = 0;
        return;
    }
    start = (start + 1 + length) % length;
    int end=index;
    while(j < length){
        j ++;
        end ++;
        temp = trunk[end % length];
        if(temp != 'w' && temp != flag){
            break;
        }
    }
    end = (end + length) % length;
    printf("Start:%d,end:%d\n",start,end);
    res[0] = start;
    res[1] = end;
}

int count_distance(int start, int end, int length){
    printf("\t%d-->%d\n",start,end);
    if(start > end){
        return length - start + end;
    }
    else if(start < end)
        return end - start;
    else
        return length;
}

int main(){
    int max_count=0,length;
    int counts[MAX_CHAIN_LENGTH],res[2];
    char data[MAX_CHAIN_LENGTH];
    char cur,next;
    FILE *fin,*fout;
    fin = fopen("beads.in","r");
    fout = fopen("beads.out","w");
    readline(fin,data);
    readline(fin,data);
    length = strlen(data);
    printf("Len:%d\n",length);
    partion(data,res,0,length);
    int fstart,start,fend,end;
    start = fstart = res[0];
    end = fend = res[1];
    int i=0,count=0;
    if(count_distance(fstart,fend,length)==length){
        max_count = length;
    }
    else{
        while(1){
            partion(data,res,(res[1])%length,length);
            count = count_distance(start,res[1],length);
            start = res[0];
            end = res[1];
            if(count>max_count){
                max_count = count;
            }
            if(fend==res[1]&&fstart==res[0])
                break;
        }
    }
    char result[1024];
    sprintf(result,"%d\n",max_count);
    fputs(result,fout);
    exit(0);
}

