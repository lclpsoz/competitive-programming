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

using pp = pair<ll, ll>;
ll mat[2000][2000];
vector<int> vals;

void bfs (int n) {
	int p = 0;
	queue<pair<pii, int>> q;
	q.push({{0, 0}, n});
	while (!q.empty()) {
		int x = q.front().x.x, y = q.front().x.y, m = q.front().y;
// 		printf ("q: %d %d, m = %d\n", x, y, m);
		q.pop();
		if (!mat[x][y])
			mat[x][y] = vals[p++];
		if (m > 1) {
			q.push ({{x, y}, m/2});
			q.push ({{x+m/2, y}, m/2});
			q.push ({{x+m/2, y+m/2}, m/2});
			q.push ({{x, y+m/2}, m/2});
		}
	}
}

pp solve (int n, int x, int y) {
	ll ret = 0, mx = 0;
	if (n == 1)
		return {mat[x][y], mat[x][y]};
	pp ax;
	ax = solve (n/2, x, y);
	mx = max (ax.y, mx);
	ret += ax.x;
	
	ax = solve (n/2, x+n/2, y);
	mx = max (ax.y, mx);
	ret += ax.x;
	
	ax = solve (n/2, x, y+n/2);
	mx = max (ax.y, mx);
	ret += ax.x;
	
	ax = solve (n/2, x+n/2, y+n/2);
	mx = max (ax.y, mx);
	ret += ax.x;
	
// 	printf ("%d (%d, %d)> %lld %lld\n", n, x, y, ret, mx);
	return {ret+mx, mx};
}

int main () {
	int n;
	scanf ("%d", &n);
	int m = 1;
	while (m*m < n) ++m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			int x;
			scanf ("%d", &x);
			vals.push_back (x);
		}
	sort (vals.begin(), vals.end(), greater<int>());
	bfs (m);
// 	for (int i = 0; i < m; i++)
// 		for (int j = 0; j < m; j++)
// 			printf ("%d%c", mat[i][j], " \n"[j==m-1]);
	printf ("%lld\n", solve (m, 0, 0).x);
	
	return 0;
}
