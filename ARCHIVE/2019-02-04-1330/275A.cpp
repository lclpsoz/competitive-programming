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

int mat[5][5];
int adj[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};

int main () {
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			mat[i][j] = 1;
		
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++) {
			int v;
			scanf ("%d", &v);
			v%=2;
			if (v)
				for (int k = 0; k < 5; k++)
					mat[i+adj[k][0]][j+adj[k][1]] ^= 1;
		}
		
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++)
			printf ("%d", mat[i][j]);
		putchar ('\n');
	}
		
	return 0;
}
