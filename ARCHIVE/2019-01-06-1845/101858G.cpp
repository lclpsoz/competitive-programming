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

const int M = 2e5+100, N = 5e5 + 100;

int n, t, total;
bool a[M];
int vals[M], qnt[N];
ll ans;
vector<int> factors[N];

int add (int x, bool state) {
	int r = 0;
	int mx = 1<<len (factors[x]);
	for (int msk = 1; msk < mx; msk++) {
		int v = 1;
		for (int i = 0; i < len (factors[x]); i++)
			if (msk & (1<<i))
				v *= factors[x][i];
		if (__builtin_popcount (msk)&1) {
			qnt[v] += state ? 1 : -1;
			r += qnt[v];
		}else {
			qnt[v] += state ? 1 : -1;
			r -= qnt[v];
		}
	}
	
	return (total - r) * (state ? 1 : -1);
}

void sieve () {
	for (int i = 2; i < N; i++)
		if (factors[i].empty())
			for (int j = i; j < N; j+=i)
				factors[j].push_back (i);
}

int main () {
	sieve ();
	
	scanf ("%d %d", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &vals[i]);
	
	for (int i = 0; i < t; i++) {
		int p, x;
		scanf ("%d", &p);
		x = vals[p];
		total += a[p] ? -1 : 1;
		a[p] = !a[p];
		if (x == 1)
			if (a[p])
				ans += total-1;
			else
				ans -= total;
		else
			ans += add (x, a[p]);
		printf ("%lld\n", ans);
	}
	
	return 0;
}
