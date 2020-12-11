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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+20;

int h, w;
int n;
vector<pii> vec;
int fact[N], invFact[N];
pii qntWays[3010];

int powMod (int b, int p) {
	int ret = 1;
	while (p) {
		if (p&1) ret = mod (ret * 1LL * b);
		b = mod (b * 1LL * b);
		p >>= 1;
	}
	
	return ret;
}

int invMod (int b) {
	return powMod (b, MOD-2);
}

int binomial (int a, int b) {
	return mod (fact[a] * 1LL * mod (invFact[a - b] * 1LL * invFact[b]));
}

int ways (int a, int b) {
	return binomial (a+b-2, a-1);
}

int main () {
	scanf ("%d %d", &h, &w);
	
	fact[0] = 1;
	invFact[0] = 1;
	int mx = max (h, w);
	for (int i = 1; i <= 2*mx; i++) {
		fact[i] = mod (fact[i-1] * 1LL * i);
		invFact[i] = invMod (fact[i]);
	}
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int r, c;
		scanf ("%d %d", &r, &c);
		vec.push_back ({r, c});
	}
	
	sort (vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		pii p = vec[i];
		qntWays[i] = {ways (p.x, p.y), ways (h-p.x+1, w-p.y+1)};
	}
	
	
	int ans = ways (h, w);
	for (int i = 0; i < n; i++) {
// 		printf ("%d %d\n", p.x, p.y);
		for (int j = 0; j < i; j++)
			if (vec[j].y <= vec[i].y)
				qntWays[i].x = mod (qntWays[i].x - mod (ways (vec[i].x-vec[j].x+1, vec[i].y-vec[j].y+1) * 1LL * qntWays[j].x));
// 		printf ("%d: %d\n", i, qntWays[i].x);
		ans = mod (ans - mod (qntWays[i].x * 1LL * qntWays[i].y));
	}
	
	printf ("%d\n", ans);

	return 0;
}
