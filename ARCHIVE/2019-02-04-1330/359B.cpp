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

int n, k;

int main () {
	scanf ("%d %d", &n, &k);
	n *= 2;
	vector<int> vec;
	if (k == 0) {
		for (int i = 1; i <= n; i++)
			vec.push_back (i);
	} else if (k == 2) {
		for (int i = 1; i <= n;) {
			vec.push_back (i);
			if (i+2 <= n)
				vec.push_back (i+2);
			else
				vec.push_back (i+1);
			if (i&1)
				++i;
			else
				i+=3;
		}
		swap (vec[0], vec[1]);
	} else {
		for (int i = 1; i <= n/2; i++) {
			vec.push_back (i);
			vec.push_back (n-i+1);
		}
		if (k&1)
			swap (vec[n-k], vec[n-k-1]);
		else {
			swap (vec[n-k+1], vec[n-k]);
			swap (vec[n-1], vec[n-2]);
		}
	}
	for (int i = 0; i < n; i++)
		printf ("%d%c", vec[i], " \n"[i==n-1]);

	return 0;
}
