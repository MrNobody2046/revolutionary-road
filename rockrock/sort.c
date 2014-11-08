#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int issort(void *data, int size, int esize,
		int (*compare)(const void *key1, const void *key2)) {
	char *a = data;
	void *key;
	int i, j;
	if ((key = (char *) malloc(esize)) == NULL)
		return -1;

	for (i = 1; i < size; i++) {
		memcpy(key, &a[i * esize], esize); // *key stored data[i]
		j = i - 1;
		while (j >= 0 && compare(&a[j * esize], key) > 0) {
			memcpy(&a[(j + 1) * esize], &a[j * esize], esize);
			j--;
		}
		memcpy(&a[(j + 1) * esize], key, esize);
	}
	free(key);
	return 0;
}

int compare(const void *key1, const void *key2) {
	return *(int *) key1 - *(int *) key2;
}

void print_array(int li[], int size) {
	int i;
	for (i = 0; i < size-1; i++) {
		printf("%d ", li[i]);
	}
	printf("%d\n",li[i++]);
}

int main() {

	int test[] = { 20, 19, 30, 15, 17, 99, };
	int (*cmp)(const void *key1, const void *key2);
	cmp = compare;
	print_array(test, 6);
	issort(test, 6, sizeof(int), *cmp);
	print_array(test, 6);
	exit(0);
}
