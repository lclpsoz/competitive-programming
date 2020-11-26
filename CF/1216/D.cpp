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

int mdc(int a, int b) {
	if(a == 0) return b;
	return mdc(b%a, a);
}

const int N = 2e5 + 100;

int a[N];

int main () {
	int n;
	scanf("%d", &n);
	int mx = -1;
	ll total = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for(int i = 0; i < n; i++) {
		a[i] = mx-a[i];
		total += a[i];
	}
	int md = a[0];
	for(int i = 1; i < n; i++)
		md = mdc(md, a[i]);
	if(md == 0) {
		printf("0 0\n");
		exit(0);
	}
	ll y = 0;
	for(int i = 0; i < n; i++)
		y += a[i]/md;
	printf("%lld %lld\n", y, total/y);

	return 0;
}
