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

int main () {
	scanf ("%d", &n);
	vector<char> ans;
	for (int i = 0; i < n; i++) {
		char c;
		scanf (" %c", &c);
		if (len(ans)%2 == 0 or c != ans.back())
			ans.push_back (c);
	}
	if (len (ans)%2) ans.pop_back();
	printf ("%d\n", n - len (ans));
	for (char c : ans)
		putchar (c);
	putchar ('\n');

	return 0;
}
