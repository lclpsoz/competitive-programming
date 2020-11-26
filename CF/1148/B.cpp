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

const int N = 2e5 + 10;

int n, m, k, ta, tb;
int a[N];
vector<int> vecB;

int main () {
	scanf ("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		a[i] += ta;
	}
	
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d", &x);
		vecB.push_back (x);
	}
	int ans = -1;
	if (k == n) {
		printf ("-1\n");
		exit (0);
	}
	for (int i = 0; i <= min (n, k); i++) {
		int now = a[i];
		int kNow = k-i;
		auto it = lower_bound (vecB.begin(), vecB.end(), now);
		int pos = it - vecB.begin();
		if (pos+kNow >= m) {
			printf ("-1\n");
			exit (0);
		} else {
			// printf ("i = %d, pos = %d\n", i, pos);
			pos += kNow;
			ans = max (ans, vecB[pos]+tb);
		}
	}
	printf ("%d\n", ans);

	return 0;
}
