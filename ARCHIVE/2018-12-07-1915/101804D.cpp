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

const int N = 1e5+100;

int n;
int bit[N];
int q, opt;

int sum (int p) {
	int r = 0;
	for (; p >= 1; p-=p&-p)
		r += bit[p];
	
	return r;
}

void add (int p, int v) {
	for (; p < N; p+=p&-p)
		bit[p] += v;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf ("%d.%d", &a, &b);
		add (i, a*100 + b);
	}
	
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &opt);
		if (opt == 1) {
			int p, a, b;
			scanf ("%d %d.%d", &p, &a, &b);
			add (p, -(sum (p) - sum(p-1)));
			add (p, 100*a + b);
		} else {
			int l, r;
			scanf ("%d %d", &l, &r);
			int val = sum (r) - sum (l-1);
			printf ("%.6Lf\n", (((ld)val)/(r-l+1))/100);
		}
	}
	
	return 0;
}
