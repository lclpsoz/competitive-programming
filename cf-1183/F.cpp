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

int q, n;
set<int> st;
vector<int> vec;

int main () {
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &n);
		while (n--) {
			int x;
			scanf ("%d", &x);
			st.insert (x);
		}
		while (!st.empty()) {
			vec.push_back (*st.begin());
			st.erase (st.begin());
		}
		reverse (vec.begin(), vec.end());
		int ans = vec[0];
		n = len (vec);
		for (int x1 = 0; x1 < n; x1++) {
			// printf ("x1 = %d\n", x1);
			int rMax = n;
			for (int x2 = x1+1; x2 < n and x2 < rMax; x2++)
				if (vec[x1]%vec[x2]) {
					// printf ("  x2 = %d\n", x2);
					ans = max (ans, vec[x1] + vec[x2]);
					for (int x3 = x2+1; x3 < n and x3 < rMax; x3++)
						if (vec[x1]%vec[x3] and vec[x2]%vec[x3]) {
							// printf ("    x3 = %d\n", x3);
							ans = max (ans, vec[x1] + vec[x2] + vec[x3]);
							rMax = x3;
							break;
						}
				}
		}
		printf ("%d\n", ans);

		vec.clear();
	}

	return 0;
}
