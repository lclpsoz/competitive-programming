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

bool checkZero () {
	int nn = n;
	while (nn > 0) {
		if (nn%10 == 0) return true;
		nn/=10;
	}
	return false;
}

void remZero () {
	while (checkZero ()) {
		// printf ("%d\n", n);
		int nn = n;
		int p = 0, pot = 1;
		while (nn%10 != 0) {
			nn/=10;
			++p;
			pot *= 10;
		}
		int ax = n%pot;
		n -= ax;
		n--;
	}
	// printf ("%d\n", n);
}

int prodV (vector<int> v) {
	int ret = 1;
	for (int i = 0; i < len (v); i++)
		if ((i != len(v)-1) or v[i])
			ret *= v[i];

	return ret;
}

int checkBr (int x) {
	int ret = 1;
	while (x) {
		ret *= x%10;
		x /= 10;
	}

	return ret;
}

int main () {
	scanf ("%d", &n);
	// for (int ax= 1; ax < 1000000; ax++) {
	// 	n = ax;
		// printf ("n = %d\n", n);
	int nnn = n;
	remZero ();
	vector<int> v;
	while (n) {
		v.push_back (n%10);
		n/=10;
	}
	int pot9 = 1;
	int ans = prodV (v);
	int bef = -1;
	for (int i = 1; i < len (v); i++) {
		if (v[i-1] != 9)	
			v[i]--, v[i-1] = 9;
		ans = max (ans, prodV (v));
		// for (int x : v)
		// 	printf ("%d", x);
		// putchar ('\n');
		// printf ("%d\n", prodV(v));
		// putchar ('\n');
	}
	printf ("%d\n", ans);
	
	// int ans2 = -1;
	// for (int i = 1; i <= nnn; i++)
	// 	ans2 = max (ans, checkBr (i));
	// assert (ans2 == ans);
	// printf ("ans = %d\n", ans);
	// }

	return 0;
}
