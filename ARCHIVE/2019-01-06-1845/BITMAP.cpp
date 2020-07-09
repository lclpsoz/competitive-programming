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

using pp = pair<pii, int>;

const int INF = 1e9;
const int N = 195;

int t, n, m;
int ans[N][N];
queue<pp> q;

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				ans[i][j] = INF;
				char c;
				scanf (" %c", &c);
				if (c == '1') q.push ({{i, j}, 0});
			}
		while (!q.empty()) {
			int x = q.front().x.x;
			int y = q.front().x.y;
			int d = q.front().y;
			q.pop();
			if (x == 0 or y == 0 or x > n or y > m or ans[x][y] != INF) continue;
			ans[x][y] = d;
			q.push ({{x+1, y}, d+1});
			q.push ({{x, y+1}, d+1});
			q.push ({{x-1, y}, d+1});
			q.push ({{x, y-1}, d+1});
		}
				
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)  {
				if (j > 1) putchar (' ');
				printf ("%d", ans[i][j]);
			}
			putchar ('\n');
		}
	}

	return 0;
}
