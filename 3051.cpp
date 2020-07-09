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

const int N = 5e5 + 10;

int n, k;
int acu[N];

int lower(int p) {
	int l = p, r = n;
	while(l < r) {
		int md = (l+r)/2;
		if(acu[md] - acu[p-1] >= k)
			r = md;
		else
			l = md+1;
	}
	if(acu[l] - acu[p-1] != k)
		return -1;
	else
		return l;
}

int upper(int p) {
	int l = p, r = n+1;
	while(l < r) {
		int md = (l+r)/2;
		if(acu[md] - acu[p-1] > k)
			r = md;
		else
			l = md+1;
	}
	if(acu[l] - acu[p-1] < k)
		return -1;
	else
		return l;
}

int main () {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		acu[i] = acu[i-1] + x;
	}
	acu[n+1] = acu[n];
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int l = lower(i);
		if(l == -1) continue;
		int r = upper(i);
		// printf("%d -> %d %d\n", i, l, r);
		ans += r-l;
	}
	printf("%lld\n", ans);

	return 0;
}
