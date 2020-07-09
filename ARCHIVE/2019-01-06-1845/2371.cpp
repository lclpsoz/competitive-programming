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

const int N = 110;

int n, m;
char mat[N][N];
int comp[N][N], qnt[N*N];

void dfs (int x, int y, int id) {
	if (mat[x][y] != '#' or comp[x][y] != 0)
		return;
	comp[x][y] = id;
	qnt[id]++;
	for (int i = -1; i <= 1; i+=2) {
		dfs (x+i, y, id);
		dfs (x, y+i, id);
	}
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf (" %c", &mat[i][j]);
		
	int id = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dfs (i, j, id++);
		
	int k, ans = 0;
	scanf ("%d", &k);
	while (k--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		if (mat[x][y] == '#') {
			mat[x][y] = '.';
			id = comp[x][y];
			qnt[id]--;
			if (!qnt[id]) ++ans;
		}
	}
	
	printf ("%d\n", ans);

	return 0;
}
