/*
ID:sphy1
LANG: C
TASK: dualpal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 32

void readline(FILE *f, char trunk[]){
    fgets(trunk,MAX_LINE_LENGTH,f);
    if(*(trunk+strlen(trunk)-1)=='\n'){
        *(trunk+strlen(trunk)-1) = '\0';
        }
}

void booken(char buffer[],char remain[]){
    int i, j, l=strlen(buffer);
    for(i=0;i<l;i++){
        if(buffer[i]==' '){
            buffer[i] = '\0';
            break;
            }
    }
    for(j=0;j<l-i-1;j++){
        remain[j]=buffer[i+j+1];
        buffer[i+j]=0;
    }
}

int is_plalindrome(char str[]){
    int len=strlen(str), i;
    int j = (len - 1) / 2;
    for(i=0;i<=j;i++){
        if(str[i]!=str[len-i-1])
            return 0;
    }
    return 1;
}

int number2ascii(int a){
    if(a<10)
        return a + 48;
    else
        return a + 55;
}

void convert_base(int num, int base, char ret[]){
    int mod, i=0;
    char temp;
    while(1){
        mod = num % base;
        num = num / base;
        if(mod!=0||num!=0){
            ret[i] = number2ascii(mod);
            i ++;
        }
        else
            break;
    }
    ret[i] = '\0';
}

void revert(char str[]){
    int i, len= strlen(str), j = (len -1) / 2;
    int temp;
    for(i=0;i<=j;i++){
        temp = str[len-i-1];
        str[len-i-1] = str[i];
        str[i] = temp;
    }
}

int is_dualpal(int num){
    int base=2, count=0;
    char temp[MAX_LINE_LENGTH];
    for(;base<=10;base++){
        convert_base(num, base, temp);
        count += is_plalindrome(temp);
        if(count>=2){
            return 1;
        }
    }
    return 0;
}

int main(){
    char temp[MAX_LINE_LENGTH], buffer[MAX_LINE_LENGTH];
    FILE *fin  = fopen ("dualpal.in", "r");
    FILE *fout = fopen ("dualpal.out", "w");
    readline(fin, temp);
    char N[MAX_LINE_LENGTH];
    booken(temp, N);
    int s = atoi(temp), n = atoi(N);
    int base, find=0, num;
    for(num=n+1;num<100000;num++){
        if(find==s)
            break;
        if(is_dualpal(num)==1){
            find ++;
            printf("Got one:%d\n",num);
            sprintf(buffer,"%d\n",num);
            fputs(buffer,fout);
        }
    }

    fclose(fin);
    fclose(fout);
    exit(0);
}

