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

const int N = 1010;

int t;
int n, m;
char mat[N][N];
int dist[N][N];

bool isValid (int x, int y) {
	return (x >= 0 and y >= 0 and x < n and y < m);
}

int main () {
	scanf ("%d", &t);
	int cas = 1;
	while (t--) {
		scanf ("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf (" %c", &mat[i][j]);
				dist[i][j] = 1e9;
			}
		
		set<pair<int, pii>> st;
		st.insert ({0, {0, 0}});
		dist[0][0] = 0;
		while (!st.empty()) {
			int d = st.begin()->x;
			pii p = st.begin()->y;
			st.erase (st.begin());
			if (d > dist[p.x][p.y]) continue;
// 			printf ("%d %d %d %c\n", p.x, p.y, d, mat[p.x][p.y]);
			char c = mat[p.x][p.y];
			for (int i = -1; i <= 1; i+=2) {
				int x = p.x+i, y = p.y;
				if (isValid (x, y) and dist[x][y] > d + (c != mat[x][y])) {
					dist[x][y] = d + (c != mat[x][y]);
					st.insert ({dist[x][y], {x, y}});
				}
				x = p.x, y = p.y+i;
				if (isValid (x, y) and dist[x][y] > d + (c != mat[x][y])) {
					dist[x][y] = d + (c != mat[x][y]);
					st.insert ({dist[x][y], {x, y}});
				}
			}
		}
		assert (false);
		printf ("Case %d: %d\n", cas++, dist[n-1][m-1]);
	}

	return 0;
}
