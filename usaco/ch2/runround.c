/*
ID:sphy1
LANG: C
TASK: runround
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "runround.in"
#define OUTPUT "runround.out"


int is_round_number(unsigned long a){
    char temp[11];
    sprintf(temp, "%lu", a);
    int length = strlen(temp);
    int i, current_number ,current_offset;
    current_offset = 0;
    for(i=0;i<=length;i++){
        if(temp[current_offset] != '*' && (current_number = (temp[current_offset] - '0')) == length){
            return 0;
        }
        temp[current_offset] = '*';
        current_offset = (current_offset + current_number) % length;
//        printf("c:%d o:%d ",current_number, current_offset);
//        printf("%s\n", temp);
    }
    return 1;

}

int main(){
    freopen(INPUT, "r", stdin);
//    freopen(OUTPUT, "w", stdout);
    unsigned long  n;
    scanf("%lu", &n);
    unsigned long s = ++n;
    while(!is_round_number(s)){
        s ++;
    }
    printf("%lu\n", s);
    exit(0);
}
