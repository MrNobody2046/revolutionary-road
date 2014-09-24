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
    int start;
    start = index + length;
    char flag, temp;
    flag = trunk[start % length];
    int j=0;
    while(j < length){
        j --;
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
    start = (start + 1) % length;
    int remain;
    remain = (index + j + length) % length;
    int end=index;
    j =0;
    while(j<remain){
        j ++;
        end ++;
        temp = trunk[end % length];
        if(temp != 'w' && temp != flag){
            break;
        }
    }
    if(end<1){
        end += length;
    }
    end = (--end) % length;

    printf("Start:%d,end:%d\n",start,end);
    res[0] = start;
    res[1] = end;
}

int count_distance(int start, int end, int length){
    if(start > end){
        return length - start + end + 1;
    }
    else
        return end - start + 1;
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
    int start,fend,end;
    start = res[0];
    fend = res[1];
    int i=0;
    printf("Start:%d,end:%d\n",start,fend);
    if(count_distance(start,fend,length)==length){
        max_count = length;
    }
    else{
        while(1){
            partion(data,res,(res[1]+1)%length,length);
            start = res[0];
            end =res[1];
            counts[i] = count_distance(start,end,length);
            printf("%d\n",count_distance(start,end,length));
            i ++;
            if((fend-end)==0)
                break;
        }
        int j,tcount;
        for(j=0;j<i;j++){
            tcount = counts[j] + counts[(j+1)%i];
            if(tcount > max_count){
                max_count = tcount;
            }
        }
    }

    char result[1024];
    printf("\n\n%d",max_count);
    sprintf(result,"%d\n",max_count);
    fputs(result,fout);
    exit(0);
}

