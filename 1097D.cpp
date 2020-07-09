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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const ll N = 1e15 + 100;
const int P = 31622776;
const int K = 1e4 + 10;

ll n;
int k;
bitset<P> not_prime;
vector<ll> factors;
vector<ll> factorsExp;
pii dp[K][60];
vector<pii> fractions;

pii operator+ (pii a, pii b) {
	if (a.x == 0 and a.y == 0) return b;
	if (b.x == 0 and b.y == 0) return a;
	return {(a.x*1LL*b.y + b.x*1LL*a.y)%MOD, (a.y * 1LL * b.y)%MOD};
}

pii operator* (pii a, pii b) {
	return {(a.x * 1LL * b.x)%MOD, (a.y * 1LL * b.y)%MOD};
}

int powMod (int b, int p) {
	int ret = 1;
	while (p) {
		if (p&1) ret = (ret * 1LL * b) % MOD;
		b = (b * 1LL * b)%MOD;
		p >>= 1;
	}

	return ret;
}

int main () {
    for (int i = 2; i*i < P; i++)
        if (not_prime[i] == 0)
            for (int j = i*i; j < P; j+=i)
                not_prime[j] = 1;

	scanf ("%lld %d", &n, &k);
	ll nFact = n;
	for (int i = 2; i < P; i++)
		if (not_prime[i] == 0) {
			while (nFact%i == 0) {
				if (factors.empty() or factors.back() != i)
					factors.push_back (i), factorsExp.push_back (0);
				factorsExp.back()++;
				nFact/=i;
			}
		}
	if (nFact > 1)
		factors.push_back (nFact), factorsExp.push_back (1);

	for (int ii = 0; ii < len (factors); ii++) {
		int p = factors[ii]%MOD;
		int eP = factorsExp[ii];
		// printf ("p = %d, eP = %d\n", p, eP);
		for (int i = 0; i <= eP; i++) dp[0][i] = {0, 0};
		dp[0][eP] = {1, 1};
		for (int i = 0; i < k; i++) {
			for (int l = 0; l <= eP; l++)
				dp[i+1][l] = {0, 0};
			for (int j = 0; j <= eP; j++) {
				pii fracNow = {1, j+1};
				fracNow = dp[i][j]*fracNow;
				// printf ("  fracNow (i = %d, j = %d) = %d/%d\n", i, j, fracNow.x, fracNow.y);
				for (int l = 0; l <= j; l++)
					dp[i+1][l] = dp[i+1][l] + fracNow;
			}
		}
		fractions.push_back({0, 0});
		ll ax = 1;
		for (int i = 0; i <= eP; i++) {
			pii now = {(ax * 1LL * dp[k][i].x)%MOD, dp[k][i].y};
			fractions.back() = fractions.back () + now;
			ax = (ax*1LL*p)%MOD;
		}
		// for (int i = 0; i <= k; i++)
		// 	for (int j = 0; j <= eP; j++)
		// 		printf ("(%d, %d)%c", dp[i][j].x, dp[i][j].y, " \n"[j==eP]);
	}
	pii ans = {1, 1};
	for (pii f : fractions) {
		ans = ans * f;
		// printf("  %d/%d\n", f.x, f.y);
	}
	// printf ("%d/%d\n", ans.x, ans.y);
	printf ("%lld\n", (ans.x * 1LL * powMod (ans.y, MOD-2))%MOD);

	return 0;
}
