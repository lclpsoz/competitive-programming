#include "stdio.h"
#include "vector"
#include "queue"
#include "utility"
#include "assert.h"
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

const int N = 1010;

char mat[N][N];
int energy[15];
int adj[][2] = {{0, 1},
				{1, 0},
				{0, -1},
				{-1, 0}};
vector<pii> toMove[15];
int res[N][N];

int main () {
	int n, m, p;
	scanf ("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= p; i++)
		scanf ("%d", &energy[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf (" %c", &mat[i][j]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mat[i][j] != '.' and mat[i][j] != '#')
				toMove[mat[i][j]-'0'].push_back ({i, j});

	bool ok = true;
	int cnt = 0;
	while (ok) {
		ok = false;
		for (int player = 1; player <= p; player++) {
			queue<pair<pii, int>> q;
			if (toMove[player].empty()) continue;
			for (pii pp : toMove[player]) {
				q.push ({pp, 0});
				mat[pp.x][pp.y] = '.';
			}
			toMove[player].clear();
			while (!q.empty()) {
				pii ppp = q.front().x;
				int x = ppp.x;
				int y = ppp.y;
				int now = q.front().y;
				q.pop();
				if (mat[x][y] == '.') {
					mat[x][y] = player+'0';
					if (now < energy[player])
						for (int i = 0; i < 4; i++) {
							int dx = x+adj[i][0];
							int dy = y+adj[i][1];
							if (mat[dx][dy] == '.')
								q.push ({{dx, dy}, now+1});
						}
					else
						toMove[player].push_back ({x, y});
				}
			}
			if (toMove[player].size()) ok = true;
		}
	}
	for (int pHere = '1'; pHere <= p+'0'; pHere++) {
		int now = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				now += mat[i][j] == pHere;
		printf ("%d ", now);
	}
	putchar ('\n');

	return 0;
}
