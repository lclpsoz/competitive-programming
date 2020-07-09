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

int main () {
	int n;
	scanf ("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		v.push_back (x);
	}
	sort (v.begin(), v.end());
	int st = n - 1 - (n%2);
	for (int i = st; i >= 0; i-=2) {
		v.push_back (v[i]);
		v[i] = -1;
	}
	for (int i = 0; i < len(v); i++)
		if (v[i] != -1)
			printf ("%d ", v[i]);
	putchar ('\n');

	return 0;
}
