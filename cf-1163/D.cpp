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

string c, s, t;

int f () {
	int qS, qT;
	qS = qT = 0;
	for (int i = 0; i <= len(c)-len(s); i++) {
		bool ok = true;
		for (int j = 0; ok and j < len (s); j++)
			if (c[i+j] != s[j]) ok = false;
		qS+=ok;
	}
	for (int i = 0; i <= len(c)-len(t); i++) {
		bool ok = true;
		for (int j = 0; ok and j < len (t); j++) {
			// cout << "i = " << i << " j = " << j << '\n';
			if (c[i+j] != t[j]) ok = false;
		}
		qT += ok;
	}
	// cout << "qS = " << qS << ' ' << "qT = " << qT << '\n';

	return qS - qT;
}

int main () {
	cin >> c >> s >> t;
	int ans = f ();
	string ax = c;
	for (int i = 0; i <= len (c)-len(s); i++) {
		bool ok = true;
		for (int j = 0; j < len (s); j++)
			if (c[j+i] != '*' and c[j+i] != s[j]) ok = false;
		if (!ok) continue;
		for (int j = 0; j < len (s); j++)
			c[j+i] = s[j];

		int now = f();
		if (now <= ans) {
			for (int j = i; j < i+len (s); j++)
				c[j] = ax[j];
		} else {
			for (int j = i; j < i+len (s); j++)
				ax[j] = c[j];
			ans = now;
		}
	}
	// cout << c << '\n' ;
	cout << ans << '\n';

	return 0;
}
