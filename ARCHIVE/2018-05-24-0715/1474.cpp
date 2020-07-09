#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MOD = 1e6;

ll n, k, l;
ll dp[MOD];

ll fst_pow (ll x, ll e) {
	ll p = x;
	ll ret = 1;
	while (e) {
		if (e&1)
			ret = (p*ret)%MOD;
		p = (p*p)%MOD;
	}

	return ret;
}

int main ()
{
	while (scanf ("%lld %lld %lld", &n, &k, &l) != EOF) {
		k %= MOD;
		l %= MOD;
		
	}
	return 0;
}
