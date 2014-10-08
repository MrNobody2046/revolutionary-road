/*
ID:sphy1
LANG: C
TASK: palsquare
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

int main(){
    char temp[MAX_LINE_LENGTH], buffer[MAX_LINE_LENGTH];
    FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");
    readline(fin, temp);
    int base, i, squared;
    base = atoi(temp);
    for(i=1;i<=300;i++){
        squared = i*i;
        convert_base(squared, base, temp);
        if(is_plalindrome(temp)==1){
            convert_base(i, base, buffer);
            printf("%s %s\n", buffer, temp);
            revert(buffer);
            printf("%s %s\n", buffer, temp);
            sprintf(buffer, "%s %s\n", buffer, temp);
            fputs(buffer, fout);
        }
    }
    fclose(fin);
    fclose(fout);
    exit(0);
}