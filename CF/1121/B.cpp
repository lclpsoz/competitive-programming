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

const int M = 1e5 + 100;

map<int, int> mp;
int n;
int a[1010];
int qnt[M];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		qnt[a[i]]++;
		for (int j = 0; j < i; j++)
			mp[a[i] + a[j]]++;
	}
	int ans = -1;
	for (auto p : mp)
		ans = max (ans, p.y);
	printf ("%d\n", ans);

	return 0;
}
