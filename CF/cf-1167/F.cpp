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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 5e5 + 10;

int n;
int bit[N], a[N];
vector<pii> vecA;

void add (int p, int v) {
	while (p < N) {
		bit[p] = (bit[p] + v)%MOD;
		p += p&-p;
	}
}

int sum (int p) {
	int ret = 0;
	while (p) {
		ret = (ret + bit[p])%MOD;
		p -= p&-p;
	}
	
	return ret;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		vecA.push_back ({a[i], i});
	}
	sort (vecA.begin(), vecA.end());

	int ans = 0;
	// Left Part
	for (auto pp : vecA) {
		int i = pp.y;
		int v = pp.x;

		ans = (ans + (((v*1LL*(n-i+1))%MOD)*1LL*sum (i))%MOD)%MOD;

		add (i, i);
	}
	// int brute = 0;
	// for (int i = 1; i <= n; i++) {
	// 	printf ("  i = %d\n", i);
	// 	for (int j = 1; j <= i; j++)
	// 		brute = (brute + a[i]*(n-i+1)*j*1LL*(a[j]<a[i]))%MOD;
	// 	printf ("    brute = %d\n", brute);
	// }
	// printf ("After Left = %d | brute = %d\n", ans, brute);

	// Right Part
	memset (bit, 0LL, sizeof bit);
	for (auto pp : vecA) {
		int i = pp.y;
		int v = pp.x;

		ans = (ans + (((v*1LL*i)%MOD)*1LL*(sum (n) - sum (i)))%MOD)%MOD;

		add (i, n-i+1);
	}

	for (int i = 1; i <= n; i++)
		ans = (ans + (a[i]*1LL*((i*1LL*(n-i+1))%MOD))%MOD)%MOD;

	printf ("%d\n", ans);


	return 0;
}
