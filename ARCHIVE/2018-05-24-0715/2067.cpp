#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n, m;
int x;
int q;
int mat[210][210];

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf ("%d", &x);
			if (x == 0)	mat[i][j] = 1;
			mat[i][j] += mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
		}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf ("%d ", mat[i][j]);
		putchar ('\n');
	}*/

	// Two pointers
	pii i, j;
	i = j = {1, 1};
	int maxi = -1;
	while (i.y <= m && (m == -1 || i.y <= m-maxi)) {
		while (i.x <= n) {
			// printf ("%d %d %d %d", i.x, i.y, j.x, j.y);
			if (j.x <= n && j.y <= m && mat[j.x][j.y]+mat[i.x-1][i.y-1]-mat[j.x][i.y-1]-mat[i.x-1][j.y] == 0) {
				// putchar ('<');
				maxi = max (maxi, j.x-i.x);
				j.x++;
				j.y++;
			} else {
				// putchar ('!');
				i.x++;
				j = {i.x+maxi, i.y+maxi};
			}
			// putchar ('\n');
		}
		i.x = 1;
		i.y++;
		j = {i.x+maxi, i.y+maxi};
	}

	maxi++;
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &x);
		printf ("%s\n", x <= maxi ? "yes" : "no");
	}

	return 0;
}
