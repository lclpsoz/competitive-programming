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

ll pd[2][20][5];

ll solve (bool dig, int p, int qnt) {
	if (qnt < 0)
		return 0;
	if (qnt == 0)
		return 1;
	
	ll &r = pd[dig][p][qnt];
	if (r != -1) return r;

	if (p)
		return r = 9*solve (1, p-1, qnt-1) + solve (0,  p-1, qnt);
	else
		return r = 1;
}

ll func (string str) {
	memset (pd, -1, sizeof pd);
	ll r = 0;
	int qnt = 3;
	for (int i = 0; i < len (str); i++) {
		if (str[i] >= '1' && qnt) {
			r += solve (0, len(str)-i-1, qnt); // '0'
			r += (str[i]-'1') * solve (1, len(str)-i-1, qnt-1); // '1' .. str[i]
		}
		if (str[i] != '0') --qnt;
		//cout << "pos:" << i << " r: " << r << '\n';
	}
	
	return r;
}

int main () {
	ll l, r;
	int q;
	cin >> q;
	while (q--) {
		cin >> l >> r;
		--l;
		l = func (to_string (l));
		//cout << "____\n";
		r = func (to_string (r));
		cout << r-l << '\n';
	}
	return 0;
}