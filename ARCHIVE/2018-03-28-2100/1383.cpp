#include <bits/stdc++.h>
using namespace std;

int t;
int mat[10][10];

// opt == 1 → row
// opt == 2 → col
bool row_col (int n, int opt)
{
	bool check[11];
	for (int i = 0; i < 11; i++)
		check[i] = false;

	if (opt == 1) {
		for (int i = 0; i < 9; i++) {
			//printf (">>(%d) %d\n", n, i);
			if (check[mat[n][i]]) {
				//printf ("%d\n", i);
				return false;
			}
			else
				check[mat[n][i]] = true;
		}
		return true;
	}
	for (int i = 0; i < 9; i++)
		if (check[mat[i][n]])
			return false;
		else
			check[mat[i][n]] = true;
	return true;
}

bool quad (int x, int y)
{
	bool check[11];
	for (int i = 0; i < 11; i++)
		check[i] = false;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (check[mat[x+i][y+j]])
				return false;
			else
				check[mat[x+i][y+j]] = true;
	return true;
}

int main ()
{
	scanf ("%d", &t);
	for (int z = 0; z < t; z++) {
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				scanf ("%d", &mat[j][k]);
		bool ans = true;
		// Rows:
		for (int i = 0; i < 9 && ans; i++)
			ans = row_col (i, 1);
		// Columns:
		for (int i = 0; i < 9 && ans; i++)
			ans = row_col (i, 2);
		// Squares:
		for (int i = 0; i < 9 && ans; i+=3)
			for (int j = 0; j < 9 && ans; j+=3)
				ans = quad (i, j);

		printf ("Instancia %d\n", z+1);
		ans ? printf ("SIM\n\n") : printf ("NAO\n\n");

	}

	return 0;
}
