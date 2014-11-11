/*
 ID:sphy1
 LANG: C
 TASK: milk3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "milk3.in"
#define OUTPUT "milk3.out"
#define MAX 20

int visited[100][100][100] = { 0 };
int records[MAX+1] = { 0 };
int a, b, c;

int search(int vol_a, int vol_b, int vol_c) {
//	printf("%d %d %d ", vol_a, vol_b, vol_c);
//	printf("%d", visited[vol_a][vol_b][vol_c]);
	if (!vol_a) {
		records[vol_c]++;
	}
	if ((vol_a + vol_b + vol_c) > c) {
		printf("ERROR");
	}
	if (visited[vol_a][vol_b][vol_c]) {
		return 0;
	} else {
		visited[vol_a][vol_b][vol_c]++;
		int avalible_a = a - vol_a, avalible_b = b - vol_b, avalible_c = c
				- vol_c;
		// pour c->a
		if (vol_c >= avalible_a)
			search(a, vol_b, vol_c - avalible_a);
		else
			search(vol_a + vol_c, vol_b, 0);
		// pour c->b
		if (vol_c >= avalible_b)
			search(vol_a, b, vol_c - avalible_b);
		else
			search(vol_a, vol_b + vol_c, 0);
		// pour a->b
		if (vol_a >= avalible_b)
			search(vol_a - avalible_b, b, vol_c);
		else
			search(0, vol_a + vol_b, vol_c);
		// pour a-> c
		if (vol_a > avalible_c)
			return 0;
		//search(0, 0, vol_c);
		else
			search(0, vol_b, vol_c - vol_b);
		// pour b->a
		if (vol_b > avalible_a)
			search(a, vol_b - a + vol_a, vol_c);
		else
			search(vol_a + vol_b, 0, vol_c);
		// pour b->c
		if (vol_b > avalible_c)
			search(vol_a, 0, vol_c - vol_a);
		else
			return 0;

	}
	return 0;
}

int main() {
	freopen(INPUT, "r", stdin);
//	freopen(OUTPUT, "w", stdout);
	scanf("%d %d %d", &a, &b, &c);
//	printf("%d ", visited[0][0][0]);
//	memset(records, 0, MAX);
//	memset(visited, 0, MAX * MAX * MAX);

	search(0, 0, c);
	int i;
	for (i = 0; i < MAX; i++) {
		if (records[i]) {
			printf("%d ", records[i]);
		}
	}
//	printf("\b\n");
	exit(0);
}
