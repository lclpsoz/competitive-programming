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

string str;

int main () {
	int n;
	cin >> n >> str;
	int l, r;
	l = r = 0;
	for (int i = 0; i < len (str); i++) {
		if (i < n/2) l += str[i]-'0';
		else r += str[i]-'0';
		if (str[i] != '4' and str[i] != '7') {
			printf ("NO\n");
			return 0;
		}
	}
	if (l == r)
		printf ("YES\n");
	else
		printf ("NO\n");
		
	return 0;
}
