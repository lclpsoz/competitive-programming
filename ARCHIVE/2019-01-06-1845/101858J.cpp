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

const int N = 1e6+100;

int n;
int bit[N];

void add (int p, int v) {
	for (; p < N; p+=p&-p)
		bit[p]+=v;
}

int sum (int p) {
	int r = 0;
	for (; p >= 1; p-=p&-p)
		r += bit[p];
	return r;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int s;
		scanf ("%d", &s); ++s;
		printf ("%d\n", n - (sum (N-1) - sum (s-1)));
		add (s, 1);
	}

	return 0;
}
