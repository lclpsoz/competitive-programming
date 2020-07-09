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

int n, m;
int mat[1010][1010];
int adj[][2] = {{0, 1},
				{1, 0},
				{-1, 0},
				{0, -1}};

void dfs(int x, int y) {
	mat[x][y] = 0;
	for(int i = 0; i < 4; i++) {
		int xx = x+adj[i][0], yy = y+adj[i][1];
		if(mat[xx][yy]) dfs (xx, yy);
	}
}

int main () {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &mat[i][j]);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(mat[i][j]) {
				++ans;
				dfs(i, j);
			}
	printf("%d\n", ans);

	return 0;
}
