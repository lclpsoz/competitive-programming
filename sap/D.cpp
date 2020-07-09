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

const int N = 21, MSK = (1<<20)+1;

int n, c;
ll dp[MSK];
vector<pair<ll, ll>> strategy;
vector<int> ans;

ll solve (int p, int msk, ll x, ll y) {
	if (-strategy[p].x > x or -strategy[p].y > y) return 0;
	ll &ret = dp[msk];
	if (ret != -1) return ret;
	x += strategy[p].x, y += strategy[p].y;
	ret = y + c*x;
	for (int i = 0; i < n; i++) {
		if (((1<<i)&msk) == 0)
			ret = max (ret, solve (i, msk | (1<<i), x, y));
	}
	return ret;
}

void recu (int p, int msk, ll x, ll y) {
	// printf ("    x = %d, y = %d\n", x, y);
	if (-strategy[p].x > x or -strategy[p].y > y) return;
	ll &ret = dp[msk];
	x += strategy[p].x, y += strategy[p].y;
	if (ret == y + c*x) {
		ans.push_back (p+1);
		return;
	}
	for (int i = 0; i < n; i++) {
		// printf ("    i(%d) = %d\n", i, (1<<i)&msk);
		if (((1<<i)&msk) == 0 and ret == solve (i, msk | (1<<i), x, y)) {
			ans.push_back (p+1);
			recu (i, msk | (1<<i), x, y);
			return;
		}
	}
	// printf ("  p = %d msk = %d, x = %d y = %d %lld\n", p, msk, x, y, ret);
}

int main () {
	ll stX, stV;
	memset (dp, -1, sizeof dp); // CHANGE TO FOR
	scanf ("%d %d", &n, &c);
	scanf ("%lld %lld", &stX, &stV);
	for (int i = 0; i < n; i++) {
		ll x, v;
		scanf ("%lld %lld", &x, &v);
		strategy.push_back ({x, v});
	}

	ll ansVal = stX*c + stV;
	for (int i = 0; i < n; i++) {
		// memset (dp, -1, sizeof dp);
		// printf ("%d\n", i);
		ansVal = max (ansVal, solve (i,1<<i, stX, stV));
	}
	// printf ("ansVal = %lld\n", ansVal);
	for (int i = 0; i < n; i++)
		if (solve (i, 1<<i, stX, stV) == ansVal) {
			recu (i, 1<<i, stX, stV);
			break;
		}
	printf ("%d\n", len (ans));
	for (int i = 0; i < len (ans); i++)
		printf ("%d%c", ans[i], " \n"[i==len(ans)-1]);

	return 0;
}
