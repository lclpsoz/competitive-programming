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

int n;
string s;
int al[500];

int main () {
	cin >> n >> s;
	ll ans = 0;
	int qnt = 0;
	char lst = '-';
	for (int i = 0; i < n; i++) {
		if (s[i] != lst) {
			al[lst] = max (al[lst], qnt);
			lst = s[i];
			qnt = 1;
		} else
			++qnt;
	}
	al[lst] = max (al[lst], qnt);
	for (int i = 0; i < 500; i++) {
		ans += al[i];
	}
	cout << ans << '\n';

	return 0;
}
