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

int n, m, k;
vector<int> obj;

bool eval (int qnt) {
	int q = m;
	int ax = k;
	for (int i = n-qnt; i < n; i++) {
		if (obj[i] <= ax)
			ax -= obj[i];
		else {
			--q;
			ax = k;
			--i;
		}
		if (q == 0)
			return false;
	}
	
	return true;
}

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		obj.push_back (x);
	}
	
	int l, r;
	l = 0, r = n;
	while (l < r) {
		int md = (l+r+1)/2;
		if (eval (md))
			l = md;
		else
			r = md-1;
	}
	
	printf ("%d\n", l);

	return 0;
}
