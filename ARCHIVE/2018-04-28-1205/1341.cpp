#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int t;
int h, w;
int n, x, y;
char mat[22][22];
char arr1[MAXN];
char arr2[MAXN];
int lcs[MAXN][MAXN];

int main ()
{
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d %d", &h, &w);
		getchar (); // '\n'
		for (int j = 1; j <= h; j++) {
			for (int k = 1; k <= w; k++)
				mat[j][k] = getchar ();
			getchar (); // '\n'
		}
		scanf ("%d %d %d ", &n, &x, &y);
		int n1 = n;
		int j = 0;
		arr1[j++] = mat[x][y];
		while (n--) {
			switch (getchar ()) {
				case 'N':
					x--; break;
				case 'S':
					x++; break;
				case 'W':
					y--; break;
				case 'E':
					y++; break;

			}
			arr1[j++] = mat[x][y];
		}
		arr1[j] = '\0';

		scanf ("%d %d %d", &n, &x, &y);
		int n2 = n;
		getchar (); //\n
		j = 0;
		arr2[j++] = mat[x][y];
		while (n--) {
			switch (getchar ()) {
				case 'N':
					x--; break;
				case 'S':
					x++; break;
				case 'W':
					y--; break;
				case 'E':
					y++; break;

			}
			arr2[j++] = mat[x][y];
		}
		arr2[j] = '\0';
		// printf ("%s\n%s\n", arr1, arr2);
		// LCSubsequence:
		lcs[n1+1][n2+1] = 0;
		for (int i = 1; arr1[i-1] != '\0'; i++) {
			bool test = true;
			for (int j = 1; arr2[j-1] != '\0'; j++)
				if (test && arr1[i-1] == arr2[j-1]) {
					lcs[i][j] = max(lcs[i][j-1]+1, lcs[i-1][j]);
					test = false;
				}
				else
					lcs[i][j] = max (lcs[i][j-1], lcs[i-1][j]);
		}
		/*for (int i = 1; arr1[i-1] != '\0'; i++) {
			for (int j = 1; arr2[j-1] != '\0'; j++)
				printf ("%d ", lcs[i][j]);
			putchar ('\n');
		}*/

		printf ("Case %d: %d %d\n", i, 1+n1-lcs[n1+1][n2+1], 1+n2-lcs[n1+1][n2+1]);

	}

	return 0;
}
