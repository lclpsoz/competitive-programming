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

const int MOD = 998244353 ;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;

int fact[N];

bool check (vector<int> vec, vector<int> &ax) {
	for (int i = 0; i < len (vec); i++) if (ax[i] != -1 and vec[i] != ax[i]) return false;
	for (int i = 2; i < len (vec); i++)
		if ((vec[i] != -1 and vec[i-2] != -1 and vec[i] == vec[i-2])) return false;
	return true;
}

int powMod (int b, int p) {
	int ret = 1;
	while (p) {
		if (p&1)
			ret = (ret * 1LL * b) % MOD;
		p >>= 1;
		b = (b*1LL*b)%MOD;
	}

	return ret;
}

int bin (int a, int b) {
	return (fact[a]*1LL*(powMod ((fact[b]*1LL*fact[a-b])%MOD, MOD-2)))%MOD;
}

int only1 (int k, int sz) {
	return (k*1LL*powMod (k-1, sz-1))%MOD;
}

int between (int k, int sz) {
	int ret = 0;
	for (int i = 0; i <= sz; i++) {
		int now = (bin(sz+1, i) * 1LL * powMod (k, sz-i))%MOD;
		ret = ((ll)ret + (now * (i%2 == 0 ? 1 : -1)) + MOD)%MOD;
	}
	return ret;
}

int oneSide (int k, int sz) {
	return powMod (k-1, sz);
}

int solve (int n, int k, vector<int> &vec) {
	vector<int> pos;
	pos.push_back (-1);
	for (int i = 0; i < len (vec); i++)
		if (vec[i] != -1) pos.push_back (i);
	pos.push_back (len(vec));
	if (len (pos) == 2)
		return only1 (k, len (vec));
	else {
		int ret = 1;
		for (int i = 1; i < len (pos); i++) {
			int sz = pos[i] - pos[i-1] - 1;
			if (pos[i-1] == -1 or i == len(pos)-1)
				ret = (ret * 1LL * oneSide (k, sz))%MOD;
			else if (sz == 1)
				ret = (ret * 1LL * ((vec[pos[i]] == vec[pos[i-1]]) ? k-1 : k-2))%MOD;
			else if (sz > 0) {
				int ax = 0;
				if (vec[pos[i]] == vec[pos[i-1]])
					ax = (sz%2 == 0 ? -1 : 1);
				ret = (ret * 1LL * (between (k, sz) + ax))%MOD;
			}
		}
		return ret;
	}
}

int main () {
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = (i*1LL*fact[i-1])%MOD;

	int n, k;
	scanf ("%d %d", &n, &k);
	vector<int> vec, evens, odds, ax(n, -1);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back (x);
		if (i%2 == 0) evens.push_back (x);
		else odds.push_back (x);
	}
	if (!check (vec, ax)) {
		printf ("0\n");
		exit (0);
	}
	int ans = solve (n, k, evens);
	ans = (ans * 1LL * solve (n, k, odds))%MOD;
	printf ("%d\n", ans);

	return 0;
}
