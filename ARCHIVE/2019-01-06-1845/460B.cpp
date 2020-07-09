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

int a, b, c;

ll powE (ll b) {
	ll r = 1;
	for (int i = 0; i < a; i++)
		r *= b;
	return r;
}

ll func (int sx) {
	return b*(powE (sx)) + c;
}

int main () {
	scanf ("%d %d %d", &a, &b, &c);
	vector<int> vec;
	for (int i = 1; i <= 81; i++) {
		ll val = func (i);
		ll aux = val;
		if (aux >= 1000000000 or aux <= 0) continue;
		int sum = 0;
		while (aux) {
			sum += aux%10;
			aux/=10;
		}
		if (sum != i) continue;
		vec.push_back (val);
	}
	printf ("%d\n", len (vec));
	for (int i = 0; i < len (vec); i++) {
		if (i) putchar (' ');
		printf ("%d", vec[i]);
	}
	if (len (vec)) putchar ('\n');
	
	return 0;
}
