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

const int MOD = 998244353;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n;

int main () {
 	scanf ("%d", &n);
	if (n <= 2)
		printf ("%d\n", n);
	else {
		int ans = 1 + (n-2)*2;
		ll acu = 1;
		for (int i = 2; i < n-1; i++) {
			acu = mod (acu * 1LL * (n-i+1));
			ans = mod (ans + (i+1)*acu*(n-i-1));
		}
		
		printf ("%d\n", mod (n*1LL*ans));
	}
	
	return 0;
}
