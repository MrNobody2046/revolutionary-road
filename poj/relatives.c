/*
 ID:sphy1
 LANG: C
 TASK: relatives
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "relatives.in"
#define OUTPUT "relatives.out"

typedef struct person {
	char *name;
	char *cname;
	int age;
	int born_age;
} person;

char TED[] = "TED";

int find_is_whos_child(person plist[], char *name, int psize) {
//	找输入的名字是谁的孩子
	int i;
	for (i = 0; i < psize; i++) {
		if (!strcmp(plist[i].cname, name)) {
			return i;
		}
	}
	return -1;
}

int find(person plist[], char *name, int psize) {
	int i;
	for (i = 0; i < psize; i++) {
		if (!strcmp(plist[i].name, name)) {
			return i;
		}
	}
	return -1;
}

void process_dataset(int size) {
	int i, age;
	char *cname, *fname;


	person *all = (person *) malloc(sizeof(person) * size);
	person *current;
	person *father;
	for (i = 0; i < size; i++) {
		scanf("%s %s %d", all[i].name, all[i].cname, &all[i].born_age);
		all[i].age = -1;
	}
	int next;
	for (i = 0; i < size; i++) {
		if (all[i].age != -1 && !strcmp(all[i].name, TED)) {
			current = all[i];
			current.age = 100;
			while ((next = find(all, current.cname, size)) != -1) {
				printf("%s %d", current.cname, current.age - current.born_age)
				current = all[next];
				current.age = current.cname, current.age - current.born_age;
			}
		}
	}

}

int main() {
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int dataset_num;
	scanf("%d", &dataset_num);
	int i, dataset_size;
	for (i = 0; i < dataset_num; i++) {
		scanf("%d", &dataset_size);
		process_dataset(dataset_size);

	}

	exit(0);
}
