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

const int INF = 1e9 + 10;
const int N = 1e5 + 10;

int k, n, a;
int dp[N];
vector<int> pos, cost;

int solve (int p) {
	if (p == len(pos)-1) return 0;
	// printf ("p: %d\n", p);
	int &ret = dp[p];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = p+1; i <= len(pos)-1 and (pos[i] - pos[p] < a ); i++)
		ret = min (ret, solve (i) + cost[i] * (pos[i] - pos[p]));

	return ret;
}

int main () {
	scanf ("%d %d %d", &k, &n, &a);
	pos.push_back (0);
	cost.push_back (0);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		pos.push_back (x);
	}
	pos.push_back (k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		cost.push_back (x);
	}
	cost.push_back (0);

	memset (dp, -1, sizeof dp);
	if (solve (0) == INF)
		printf ("-1\n");
	else
		printf ("%d\n", dp[0]);

	// for (int i = 0; i < len(pos); i++)
	// 	printf ("dp[%d] = %d\n", i, dp[i]);

	return 0;
}