#include <bits/stdc++.h>
using namespace std;

int n, modi, qnt;
int mat[110][210];

int main () {

	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &modi, &qnt);
		int x, y;
		for (int j = 0; j < qnt; j++) {
			scanf ("%d", &x);
			y = x;
			x %= modi;
			int k = 0;
			while (mat[x][k])
				k++;
			mat[x][k] = y;
		}
		for (int j = 0; j < modi; j++) {
			printf ("%d -> ", j);
			int k = 0;
			while (mat[j][k]) {
				printf ("%d -> ", mat[j][k]);
				mat[j][k++] = 0;
			}
			printf ("\\\n");

		}
		if (i+1 < n)
			printf ("\n");
	}
	return 0;
}
