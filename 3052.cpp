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
char mat[505][505];
bool vis[505][505];
queue<pii> q;

int main () {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			scanf(" %c", &mat[i][j]);
			if(mat[i][j] == 'o') {
				q.push({i+1, j});
				q.push({i, j+1});
				q.push({i, j-1});
			}
		}
	
	while(!q.empty()) {
		pii now = q.front();
		q.pop();
		int x = now.x, y = now.y;
		if(vis[x][y]) continue;
		vis[x][y] = true;
		if(mat[x][y] != '.') continue;
		if(mat[x-1][y] == 'o' or
			(mat[x][y-1] == 'o' and mat[x+1][y-1] == '#') or
			(mat[x][y+1] == 'o' and mat[x+1][y+1] == '#')) {
			mat[x][y] = 'o';
			q.push({x+1, y});
			q.push({x, y+1});
			q.push({x, y-1});
		}
	}
	

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			putchar(mat[i][j]);
		putchar('\n');
	}

	return 0;
}
