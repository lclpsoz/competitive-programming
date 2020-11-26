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

const int N= 2e5 + 10;

int n, m, q;
set<pii> st;
int a[N], b[N], nxt[N];
bool ok[N];

int main () {
	scanf ("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		if (i == n-1)
			nxt[a[i]] = a[0];
		if (i)
			nxt[a[i-1]] = a[i];
	}
	for (int i = 0; i < m; i++)
		scanf ("%d", &b[i]);

	int l = 0, r = 0;
	while (r < m) {
		printf ("%d %d\n", l, r);
		while (r == 0 or (r < m and !ok[r] and nxt[b[r-1]] == b[r])) {
			ok[r] = true;
			++r;
			if (r-l == n) {
				if (nxt[r-1] == b[l])
					st.insert ({l, r});
				ok[l] = false;
				++l;
			}
		}
		printf ("2: %d %d\n", l, r);
		while (r < m and ok[r]) {
			ok[l] = false;
			++l;
		}
		printf ("3: %d %d\n", l, r);
		while (r < m and nxt[b[r-1]] != b[r]) {
			++r;
			printf ("r = %d\n", r);
			printf ("%d %d\n", nxt[b[r-1]], b[r]);
			l = r;
		}
		printf ("4: %d %d\n", l, r);
	}
	for (auto p : st)
		printf ("|%d %d\n", p.x, p.y);
	while (q--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		auto it = st.find ({x, -1});
		if (it != st.end())
			printf ("%d", it->y <= y);
		else
			printf ("0");
	}
	putchar ('\n');

	return 0;
}
