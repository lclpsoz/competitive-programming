#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

char mat[10][10];
int adj[][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int main () {
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			scanf (" %c", &mat[i][j]);
	
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++) {
			int q1, q2;
			q1 = q2 = 0;
			for (int k = 0; k < 4; k++)
				if (mat[i+adj[k][0]][j+adj[k][1]] == '.')
					q1++;
				else if (mat[i+adj[k][0]][j+adj[k][1]] == '#')
					q2++;
// 			printf ("%d %d %d %d\n", i, j, q1, q2);
			if (q1 >= 3 or q2 >= 3) {
				printf ("YES\n");
				exit (0);
			}
		}
	printf ("NO\n");

	return 0;
}
