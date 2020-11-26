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
set<int> st;
deque<int> dq;

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		if (st.count (x) == 0) {
			st.insert (x);
			if (len (dq) == k) {
				st.erase (dq.back());
				dq.pop_back ();
			}
			dq.push_front (x);
		}
	}
	printf ("%d\n", len (dq));
	for (int v : dq)
		printf ("%d ", v);
	putchar ('\n');

	return 0;
}
