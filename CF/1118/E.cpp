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

int n, k;
vector<pii> ans;

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= k and len (ans) < n; i++)
		for (int j = i+1; j <= k and len (ans) < n; j++) {
			ans.push_back ({i, j});
			ans.push_back ({j, i});
		}
		
	if (len (ans) < n)
		printf ("NO\n");
	else {
		printf ("YES\n");
		for (int i = 0; i < n; i++) {
			pii p = ans[i];
			printf ("%d %d\n", p.x, p.y);
		}
	}

	return 0;
}
