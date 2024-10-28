#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// t0 = 0, t1 = 0, t2 = 0, t3 = 1
// tn = t(n-1) + t(n-2) + t(n-3) + t(n-4), n > 3

// Recursive Function
int tet_recursive(int n, int* cnt) {
	(*cnt)++;// function call count update

	if (n < 3) return 0;
	else if (n == 3) return 1;
	else return (tet_recursive(n - 4, cnt) + tet_recursive(n - 3, cnt) + tet_recursive(n - 2, cnt) + tet_recursive(n - 1, cnt));
}

// for Loop & array Function
int tet_forloop(int n) {
	int* tlist = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i <= n; i++) {
		if (i < 3) tlist[i] = 0;
		else if (i == 3) tlist[i] = 1;
		else tlist[i] = tlist[i - 1] + tlist[i - 2] + tlist[i - 3] + tlist[i - 4];
	}

	return tlist[n];
}


int main() {
	int n;
	scanf("%d", &n);

	int* cnt = (int*)malloc(sizeof(int)); // recursive function call count
	*cnt = 0;

	int t = tet_recursive(n, cnt);

	printf("Recursive : %d (call %d times)\nfor Loop  : %d", t, *cnt, tet_forloop(n));
	return 0;
}