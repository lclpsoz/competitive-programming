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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

string a;
ll b;

int main () {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	ll ans = 0;
	for(int i = 0; i < len(a); i++) {
		ans += a[i]-'0';
		// printf("|%lld\n", ans);
		ans %= b;
		ans *= 10;
	}
	printf("%lld\n", ans/10);

	return 0;
}
