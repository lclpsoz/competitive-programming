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

const int MAXN = 11, MSK = (1<<10) + 10;

int t, maxX, maxY, stX, stY, n;
pii coord[MAXN];
int dp[MAXN][MSK];

int dist (pii a, pii b) {
	return abs (a.x-b.x) + abs (a.y-b.y);
}

int solve (int now, int msk, int en) {
	if ((msk+1) == (1<<n))
		return dist (coord[now], coord[en]);
	
	int &ret = dp[now][msk];
	if (ret != -1 ) return ret;
	ret = 2e9;
	for (int i = 0; i < n; i++)
		if (!(msk & (1<<i)))
		ret = min (ret, solve (i, msk | (1<<i), en) + dist (coord[now], coord[i]));
	
	return ret;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		memset (dp, -1, sizeof dp);
		scanf ("%d %d", &maxX, &maxY);
		scanf ("%d %d", &stX, &stY);
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf ("%d %d", &x, &y);
			coord[i] = {x, y};
		}
		int ans = 2e9;
		if (n == 1)
			ans = dist (coord[0], {stX, stY})*2;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				ans = min (ans, solve (i, (1<<i) | (1<<j), j) + dist (coord[i], {stX, stY}) + dist (coord[j], {stX, stY}));
		printf ("The shortest path has length %d\n", ans);
	}

	return 0;
}
