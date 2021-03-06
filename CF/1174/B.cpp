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

const int N = 1e5 + 100;

int n, a[N];
vector<pii> vec[2];

int main () {
	scanf ("%d", &n);
	bool odd, even;
	odd = even = false;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		if (a[i]%2 == 0) even = true;
		else odd = true;
	}
	if (odd and even)
		sort (a, a+n);
	
	for (int i = 0; i < n; i++) printf ("%d ", a[i]);
	putchar ('\n');
	


	return 0;
}
