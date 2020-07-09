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

const int N = 1e5+10;

int t;
int ans[N];

int main () {
	scanf ("%d", &t);
	while (t--) {
		int n;
		scanf ("%d", &n);
		vector<pair<pii, int>> vec;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf ("%d %d", &x, &y);
			vec.push_back ({{x, y}, i});
		}
		sort (vec.begin(), vec.end());
		int g1 = vec[0].x.y;
		ans[vec[0].y] = 1;
		bool ok = false;
		for (int i = 1; i < n; i++) {
			pii p = vec[i].x;
			int id = vec[i].y;
			if (g1 >= p.x) {
				ans[id] = 1;
				g1 = max (g1, p.y);
			}
			else {
				ans[id] = 2;
				ok = true;
			}
		}
		if (!ok)
			printf ("-1\n");
		else
			for (int i = 0; i < n; i++)
				printf ("%d%c", ans[i], " \n"[i==(n-1)]);
	}

	return 0;
}
