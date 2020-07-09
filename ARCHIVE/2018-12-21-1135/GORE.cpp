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

int t;
int n, d;
vector<int> all, vec;

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &d);
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf ("%d %d", &x, &y);
			x += y;
			vec.push_back (x);
			all.push_back (x);
		}
		sort (all.begin(), all.end());
		for (int i = 0; i < n; i++)
			printf ("%d ", all[i]);
		putchar ('\n');
		for (int i; i < n; i++) {
			if (i)
				putchar (' ');
			auto itSt = lower_bound (all.begin(), all.end(), vec[i]-d);
			auto itEn = upper_bound (all.begin(), all.end(), vec[i]+d);
			printf ("%d", (int)(itEn - itSt)-1);
		}
		putchar ('\n');
		all.clear();
		vec.clear();
	}
	
	return 0;
}
