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

const int N = 5e5 + 10;

int m, k, n, s;
int l, r;
int a[N], q[N], qNow[N];

int main () {
	scanf ("%d %d %d %d", &m, &k, &n, &s);
	for (int i = 0; i < m; i++)
		scanf ("%d", &a[i]);
	for (int i = 0; i < s; i++) {
		int x;
		scanf ("%d", &x);
		q[x]++;
	}

	int canRem = m - (k*n);
	int segSz = k + canRem;
	l = 0, r = 0;
	int lack = s;
	while (r < segSz) {
		qNow[a[r]]++;
		if (q[a[r]] and qNow[a[r]] <= q[a[r]])
			--lack;
		++r;
	}
	while (lack and l < m) {
		// printf ("(%d, %d): lack = %d\n", l, r, lack);

		// next
		do {
			qNow[a[l]]--;
			if (q[a[l]] and qNow[a[l]] < q[a[l]])
				++lack;
			++l;
			if (r < m) {
				qNow[a[r]]++;
				if (q[a[r]] and qNow[a[r]] <= q[a[r]])
					--lack;
				++r;
			}
		} while (l < m and l%k);
	}
	if (lack != 0)
		printf ("-1\n");
	else {
		vector<int> ans;
		// printf ("(%d, %d)\n", l, r);
		for (int i = l; i < r; i++) {
			if (q[a[i]]) {
				q[a[i]]--;
			} else if (canRem) {
				ans.push_back (i+1);
				canRem--;
			}
		}
		printf ("%d\n", len (ans));
		for (int v : ans)
			printf ("%d ", v);
		putchar ('\n');
	}


	return 0;
}
