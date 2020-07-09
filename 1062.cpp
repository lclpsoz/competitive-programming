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

int n;

int main () {
	while (scanf ("%d", &n), n) {
		int x;
		while (scanf ("%d", &x), x) {
			stack<int> st, station;
			for (int i = n; i >= 1; i--) st.push (i);
			while (station.empty () or station.top() != x) {
				station.push (st.top());
				st.pop();
			}
			station.pop();
			bool ok = true;
			for (int i = 2; i <= n; i++) {
				scanf ("%d", &x);
				if (ok) {
					while (len(st) and (station.empty() or station.top() != x)) {
						station.push (st.top());
						st.pop();
					}
					if (station.empty() or station.top() != x)
						ok = false;
					else
						station.pop();
				}
			}
			printf ("%s\n", ok ? "Yes" : "No");
		}
		putchar ('\n');
	}

	return 0;
}
