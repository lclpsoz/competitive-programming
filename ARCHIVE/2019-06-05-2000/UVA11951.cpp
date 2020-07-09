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

using pll = pair<ll, ll>;

int t, n, m;
ll money;
ll mat[110][110];
deque<ll> dq;

ll sum (int l, int r, int h) {
	return mat[h][r] - mat[h][l-1];	
}

pll solve () {
	pll ret = {0, 0};
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++) {
			ll total = 0;
			while (!dq.empty()) dq.pop_back ();
			for (int k = 1; k <= n; k++) {
				ll x = sum (i, j, k);
				total += x;
				dq.push_back (x);
				if (total > money) {
					total -= dq.front();
					dq.pop_front ();
				}
				ll area = len (dq) * (j-i+1);
				if (ret.x < area or (ret.x == area and ret.y > total))
					ret = {area, total};
// 				printf ("%d %d %d (%d) %lld\n", i, j, k, len (dq), total);
			}
		}
	return ret;
}

int main () {
	scanf ("%d", &t);
	for (int ca = 1; ca <= t; ca++) {
		scanf ("%d %d %lld", &n, &m, &money);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				scanf ("%lld", &mat[i][j]);
				mat[i][j] += mat[i][j-1];
			}
		
		pll ans = solve ();
		printf ("Case #%d: %lld %lld\n", ca, ans.x, ans.y);
	}

	return 0;
}
