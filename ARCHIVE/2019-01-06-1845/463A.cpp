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

const int N = 1e4+100;

int n, s;
int x, y;
bool pd[N];

int main () {
	memset (pd, 0, sizeof pd);
	scanf ("%d %d", &n, &s);
	s *= 100;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &x, &y);
		int val = 100*x + y;
		
		for (int j = val; j <= s; j+=val)
			ans = max (ans, (100 - val%100)%100);
	}
	
	printf ("%d\n", ans);
	
	return 0;
}
