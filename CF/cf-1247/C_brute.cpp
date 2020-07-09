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

int n, p;
int a[30];
set<ll> st;

int main () {
	scanf ("%d %d", &n, &p);
	for (int i = 0; i < 30; i++)
		a[i] = (1<<i) + p;

	queue<pair<ll, int>> q;
	q.push ({0, 0});
	for (int i = 0; i < 1e6 and q.front().x != n; i++) {
		ll v = q.front().x, qnt = q.front().y;
		// printf ("  %d %lld\n", qnt, v);
		q.pop();
		if (st.count (v)) continue;
		// printf ("%d %lld\n", qnt, v);
		st.insert (v);
		for (int j = 0; j < 30; j++)
			if (st.count (v+a[j]) == 0)
				q.push ({v + a[j], qnt+1});
	}
	if (q.empty() or q.front().x != n)
		printf ("-1\n");
	else
		printf ("%d\n", q.front().y);

	return 0;
}
