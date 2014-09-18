/*
ID:sphy1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>

struct person
{
	char name;
	int revenue;
};


void readline(char buffer[],FILE *f){
    fgets(buffer, 100, f);
};

char *get_line(FILE *f){
    char* buffer = (char*)calloc(100,sizeof(char*));
    fgets(buffer, 100, f);
    return buffer;
};


int main(){
	FILE *fin, *fout;
	int person_num;
	char buffer[20];
	char* chunk;
	fin = fopen("gift1.in","r");
	fout = fopen("gift1.out","w");
	readline(buffer,fin);
	person_num = atoi(buffer);
	readline(buffer,fin);
	printf("%s",buffer);
	chunk = get_line(fin);
	printf("%s",chunk);

}
