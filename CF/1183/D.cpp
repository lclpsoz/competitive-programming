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

const int N = 2e5 + 100;

int q, n;
int a[N];

int main () {
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) a[i] = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			a[x]++;
		}
		vector<int> vec;
		for (int i = 1; i <= n; i++)
			if (a[i])
				vec.push_back (a[i]);
		sort (vec.begin(), vec.end());
		int ans = 0;
		int lst = 1e9;
		while (lst and !vec.empty()) {
			int now = vec.back();
			vec.pop_back ();
			if (now >= lst)
				now = lst-1;
			lst = now;
			ans += now;
		}
		printf ("%d\n", ans);
	}

	return 0;
}
