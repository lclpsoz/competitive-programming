#include <bits/stdc++.h>
using namespace std;

int n, ans, aux;
int i, j;
int mat[12][12];
bool test = true;

int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf ("%d", &mat[i][j]);
	//First row
	for (i = 0; i < n; i++)
		ans += mat[0][i];
	//Others rows
	for (i = 1; i < n && test; i++) {
		aux = 0;
		for (j = 0; j < n; j++)
			aux += mat[i][j];
		if (aux != ans)
			test = false;
	}
	//Columns
	for (i = 0; i < n && test; i++) {
		aux = 0;
		for (j = 0; j < n; j++)
			aux += mat[j][i];
		if (aux != ans)
			test = false;
	}
	//Principal diagonal
	aux = 0;
	for (i = 0; i < n && test; i++) {
		aux += mat[i][i];
	}
	if (aux != ans)
		test = false;
	//Secondary diagonal
	aux = 0;
	for (i = 0, j = n-1; i < n && test; i++, j--) {
		aux += mat[i][j];
	}
	if (aux != ans)
		test = false;
	test ? printf ("%d\n", ans) : printf ("-1\n");

	return 0;
}
