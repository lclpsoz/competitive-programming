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

int q;

int main () {
	scanf("%d", &q);
	while(q--) {
		ll n, m;
		scanf ("%lld %lld", &n, &m);
		ll qnt = n/m;
		m%=10;
		int val = m;
		vector<int> vec;
		do {
			vec.push_back(val);
			val = (val + m)%10;
		} while(val != m);
		ll all = 0, ans = 0;
		for (int v : vec)
			all += v;
		for (int i = 0; i < qnt%len(vec); i++)
			ans+=vec[i];
		ans += all*(qnt/len(vec));
		printf("%lld\n", ans);
	}

	return 0;
}