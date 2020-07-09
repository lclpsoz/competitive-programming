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

const int N = 2e5 + 10;

ll dp[N][10];
ll mat[N][4], mx[N][4];

int n;

ll solve (int d, int qnt) {
	if (d > n) return 0;
	ll &ret = dp[d][qnt];
	if (ret != -1) return ret;

	ret = max (ret, solve (d+1, qnt));
	for (int i = 1; i <= 3; i++)
		if (mat[d][i] != -1) {
			ll now = solve (d+1, (qnt + i)%10) + mat[d][i];
			if (qnt+i >= 10)
				now += mx[d][i];
			ret = max (ret, now);
		}

	return ret;
}

int main () {
	memset (mat, -1, sizeof mat);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 10; j++)
			dp[i][j] = -1;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf ("%d", &k);
		vector<int> vec;
		int mx3 = -1, mx2 = -1;
		while (k--) {
			int c, d;
			scanf ("%d %d", &c, &d);
			if (c == 1)
				vec.push_back (d);
			else if (c == 2)
				mx2 = max (mx2, d);
			else
				mx3 = max (mx3, d);
		}
		sort (vec.begin(), vec.end(), greater<int>());

		// 1
		mat[i][1] = max (mx2, mx3);
		if (len (vec))
			mat[i][1] = max ((ll)vec[0], mat[i][1]);
		mx[i][1] = mat[i][1];

		// 2
		if (len (vec) > 1) {
			mat[i][2] = vec[0] + vec[1];
			mx[i][2] = vec[0];
		}
		if (len (vec) and mx2 != -1) {
			mat[i][2] = max (mat[i][2], (ll)mx2 + vec[0]);
			mx[i][2] = max (vec[0], mx2);
		}

		// 3
		if (len (vec) > 2) {
			mat[i][3] = (ll)vec[0] + vec[1] + vec[2];
			mx[i][3] = max (vec[0], max (vec[1], vec[2]));
		}
	}
	printf ("%lld\n", solve (1, 0));
	// for (int i = 1; i <= n; i++)
	// 	for (int j = 0; j < 10; j++)
	// 		printf ("%3d%c", dp[i][j], " \n"[j==9]);

	return 0;
}
