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

const int N = 22*22;

int n, m;
char hor[25], vert[25];
bool adj[N][N];

int main () {
	scanf ("%d %d", &n, &m);
	scanf ("%s %s", hor, vert);
	for (int i = 0; i < n*m; i++) {
		char h = hor[i/m];
		char v = vert[i%m];
		if (h == '>' and i%m < m-1)
			adj[i][i+1] = true;
		else if (h == '<' and i%m)
			adj[i][i-1] = true;
		
		if (v == '^' and i-m >= 0)
			adj[i][i-m] = true;
		else if (v == 'v')
			adj[i][i+m] = true;
	}

	for (int k = 0; k < n*m; k++)
		for (int i = 0; i < n*m; i++)
			for (int j = 0; j < n*m; j++) {
				if (i == j)
					adj[i][j] = true;
				else
					adj[i][j] = adj[i][j] or (adj[i][k] and adj[k][j]);
			}
	for (int i = 0; i < n*m; i++)
		for (int j = 0; j < n*m; j++)
			if (!adj[i][j]) {
				printf ("NO\n");
				return 0;
			}
	printf ("YES\n");
	
	return 0;
}
