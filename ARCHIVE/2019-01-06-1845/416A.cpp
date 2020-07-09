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
int l = -2'000'000'000, r = 2'000'000'000;

int main () {
	cin >> n;
	while (n--) {
		string opt, ans;
		int val;
		cin >> opt >> val >> ans;
		if (ans == "N") {
			if (opt == ">") opt = "<=";
			else if (opt == ">=") opt = "<";
			else if (opt == "<") opt = ">=";
			else if (opt == "<=") opt = ">";
		}
		if (len (opt) == 1) val += (opt[0] == '>' ? 1 : -1);
		if (opt[0] == '>')
			l = max (l, val);
		else
			r = min (r, val);
	}
	if (l <= r)
		printf ("%d\n", l);
	else
		printf ("Impossible\n");

	return 0;
}
