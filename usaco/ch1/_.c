/*
ID:sphy1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h> 


int main(){
    char tmp[7],*ptmp;
    char buffer[] = "A test";
    char *a="A";
    printf("%s\n",buffer);a
    int p1=1,p2=1;
    if(buffer[0]==65){
        printf("%s\n\n","passed 65");
    }
    if(buffer[0]==*a){
        printf("%s\n\n","passed A");
    }

    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    for(ptmp=tmp,scanf("%s",tmp);*ptmp!='\0';p1*=*ptmp++-64);
    for(ptmp=tmp,scanf("%s",tmp);*ptmp!='\0';p2*=*ptmp++-64);
    printf(p1%47==p2%47?"GO\n":"STAY\n");
    return 0;
}
