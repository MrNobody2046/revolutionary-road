/*
ID:sphy1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int char2int(char *str){
	int i, size, ret;
	size = sizeof(str)/sizeof(str[0]);
	ret = 1;
	for(i=0;i<size;i++){
		ret = ret * (str[i] % 65 + 1);
	}
	return ret;
}

void main(){
	FILE *fin, *fout;
	char comet[6],team[6],stat[4];
	int strsize=8,i;
	fin = fopen("ride.in","r");
	fout = fopen("ride.out","w");
	fgets(comet,strsize,fin);
	printf("Comet is:%s",comet);
	fgets(team,strsize,fin);
	printf("Team is:%s",team);
	if((char2int(comet) % 47)==(char2int(team) % 47)){
		strcpy(stat,"GO");
	}
	else{
		strcpy(stat,"STAT");
	};
	printf("%s",stat);
	fputs(stat,fout);
	fclose(fin);
	fclose(fout);
	exit(0);

}
