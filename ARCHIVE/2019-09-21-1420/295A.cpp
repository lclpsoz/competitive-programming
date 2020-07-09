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

const int N = 1e5 + 10;

int n, m, k;
ll a[N];
int le[N], ri[N];
ll de[N];
ll delta[N];

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &a[i]);
	for (int i = 1; i <= m; i++) {
		int l, r, d;
		scanf ("%d %d %d", &l, &r, &d);
		le[i] = l, ri[i] = r, de[i] = d;
	}
	while (k--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		delta[x]++;
		delta[y+1]--;
	}
	
	ll qnt = 0;
	for (int i = 1; i <= m; i++) {
		qnt += delta[i];
		de[i] *= qnt;
	}		
	
	for (int i = 1; i <= n; i++)
		delta[i] = 0;
	
	for (int i = 1; i <= m; i++) {
		delta[le[i]] += de[i];
		delta[ri[i]+1] -= de[i];
	}
	
	qnt = 0;
	for (int i = 1; i <= n; i++) {
		qnt += delta[i];
		a[i] += qnt;
	}
	
	for (int i = 1; i <= n; i++)
		printf ("%lld%c", a[i], " \n"[i==n]);

	return 0;
}
