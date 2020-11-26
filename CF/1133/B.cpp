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

int mp[102];

int main () {
	int n, k;
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		x %= k;
		mp[x]++;
	}
	
	int ans = mp[0]/2;
	if (k%2 == 0)
		ans += mp[k/2]/2;
	for (int i = 1; i < (k+1)/2; i++)
		ans += min (mp[i], mp[k-i]);
	
	printf ("%d\n", ans*2);

	return 0;
}
