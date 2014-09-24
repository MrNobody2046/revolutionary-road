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

int get_edge(char trunk[],int length){
    int i;
    char cur,next;
    for(i=0;i<length;i++){
        cur = trunk[i%length];
        next = trunk[(i+1)%length];
        if(cur!=next&&cur!="w"&&next!="w"){
            return i+1; // find the break point
        }
    }
}

int main(){
    int start,max_count,len,i;
    int counts[MAX_CHAIN_LENGTH];
    char data[MAX_CHAIN_LENGTH];
    char cur,next;
    FILE *fin,*fout;
    fin = fopen("beads.in","r");
    readline(fin,data);
    len = strlen(data);
    start = get_edge(data,len);
    cur = data[start%len];
    i = 0;
    for(i=0;i<len;i++){
        next = data[(start+1)%len]]
        if(next==cur||next=="w"){
            start += 1;
        }
        else{
            counts[i] = start;
            i++;
            if(data[start%len]=="w"){
                start = 2;
            }
            else
                start = 1;
            cur = next;
        }
        start++;
    }
    int j;
    for(j=0;j<i;j++){
        printf("%d,",counts[j]);

    }
    exit(0);
}

