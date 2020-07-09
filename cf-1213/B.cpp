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

int n, t;

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		reverse(v.begin(), v.end());
		int ans = 0, mn = 1e9;
		for (int i = 0; i < n; i++) {
			if(v[i] < mn) {
				mn = v[i];
			} else if (v[i] > mn)
				++ans;
			// printf("%d %d\n", v[i], mn);
		}
		printf("%d\n", ans);
	}

	return 0;
}
