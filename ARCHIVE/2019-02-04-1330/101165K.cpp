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

const int N = 1e4+10;

int n;
int sectors[N];
int a[N], kOrd[N], vals[N];
int bit[N];

int sum (int p) {
	int ret = 0;
	for (; p >= 1; p-=p&-p)
		ret += bit[p];
	
	return ret;
}

void add (int p, int v) {
	for (; p < N; p+=p&-p)
		bit[p] += v;
}

ll eval (int k, int qnt) {
	memset (bit, 0, sizeof bit);
	for (int i = 0; i < qnt; i++)
		sectors[i] = 0;
	
	for (int i = 0; i < n; i++) {
		int secNow = (a[i]-1)/k;
		vals[i] = secNow*k + sectors[secNow] + 1;
		sectors[secNow]++;
	}
	
	ll ret = 0;
	for (int i = n-1; i >= 0; i--) {
		ret += sum (vals[i]);
		add (vals[i], 1);
	}

	return ret;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	
	pair<int, ll> ans = {-1, (ll)1e18l};
	for (int k = 1; k <= n/2; k++)
		if (n%k == 0) {
			ll cost = k*eval (k, n/k);
			if (cost < ans.y)
				ans = {k, cost};
		}
		
	printf ("%d %lld\n", ans.x, ans.y);

	return 0;
}
