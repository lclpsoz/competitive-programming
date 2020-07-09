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

const int INF = 1e9;
const int N = 102, MSK = (1<<15) + 10;

int t;
int n, m;
vector<int> vec;
int dp[N][MSK];

int solve (int p, int msk) {
	if ((msk + 1) == (1<<n))
		return 0;
	if (p == m)
		return INF;
	
	int &ret = dp[p][msk];
	if (ret != -1)
		return ret;
	
	ret = min (solve (p+1, msk ^ vec[p]) + 1,
						solve (p+1, msk));
	
// 	printf ("%d %d %d\n", p, msk, ret);
	return ret;
}

int main () {
	int caso = 1;
	scanf ("%d", &t);
	while (t--) {
		vec.clear();
		memset (dp, -1, sizeof dp);
		scanf ("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int val = 0;
			for (int j = 0; j < n; j++) {
				int x;
				scanf ("%d", &x);	
				if (x)
					val |= (1<<j);
			}
// 			printf ("|%d\n", val);
			vec.push_back (val);
		}

		int ans = solve (0, 0);
		printf ("Case %d: ", caso++);
		if (ans > 1000)
			printf ("IMPOSSIBLE");
		else
			printf ("%d", ans);
		putchar ('\n');
	}

	return 0;
}
