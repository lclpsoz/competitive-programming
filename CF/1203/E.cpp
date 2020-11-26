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

const int N = 150100;

int n;
int a[N], b[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		a[x]++;
	}
	for (int i = N-1; i >= 1; i--) {
		if (a[i] and !b[i+1]) {
			b[i+1]++;
			a[i]--;
		}
		if (a[i] and !b[i]) {
			b[i]++;
			a[i]--;
		}
		if (a[i]) {
			b[i-1]++;
			a[i]--;
		}
		b[i] += a[i];
	}
	// for (int i = 1; i <= 10; i++) printf ("%d\n", b[i]);
	int ans = 0;
	for (int i = 1; i < N; i++)
		if (b[i]) ++ans;
	printf ("%d\n", ans);

	return 0;
}
