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
set<int> st, vis;

int main () {
	scanf ("%d", &n);
	vector<int> ans;
	int lst = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		if (x < 0) {
			if (st.count (-x) == 0) {
				printf ("-1\n");
				exit (0);
			}
			st.erase (-x);
		} else {
			if (vis.count (x) == 1) {
				printf ("-1\n");
				exit (0);
			}
			st.insert (x);
			vis.insert (x);
		}
		if (len (st) == 0) {
			ans.push_back (i-lst);
			lst = i;
			vis.clear();
		}
	}
	if (len (st)) {
		printf ("-1\n");
		exit (0);
	}
	printf ("%d\n", len (ans));
	for (int x : ans)
		printf ("%d ", x);
	putchar ('\n');

	return 0;
}
