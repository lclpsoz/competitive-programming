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

const int MSK = (1<<16) + 10;

int n;
int a[20][20];
ll dp[MSK];
ll eval[MSK];
bool vis[MSK], visEval[MSK];
int mskN;

ll funcEval (int msk) {
	ll &ret = eval[msk];
	if (visEval[msk]) return ret;
	visEval[msk] = true;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if ((msk&(1<<i)) and (msk&(1<<j)))
				ret += a[i][j];
			
// 	printf ("    EVAL: %d %lld\n", msk, ret);
	return ret;
}

ll solve (int msk) {
	if (msk == 0) return 0;
// 	printf ("%d\n", msk);'
	ll &ret = dp[msk];
	if (vis[msk]) return ret;
	vis[msk] = true;
	for (int s = msk; s; s = (s-1)&msk) {
		ret = max (ret, funcEval (s) + solve ((~s)&msk));
//  		printf ("  msk: %d, s: %d, ret: %lld\n", msk, s, ret);
	}
	
//  	printf ("%d %lld\n", msk, ret);
	return ret;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &a[i][j]);
	mskN = (1<<n)-1;
	printf ("%lld\n", solve (mskN));

	return 0;
}