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

const int N = 2e5 + 10;

int q;
char str[N];
int ax[N];

int main () {
	scanf ("%d", &q);
	while (q--) {
		int n, k;
		scanf ("%d %d %s", &n, &k, str);
		for (int i = 0; i < n; i++)
			if (str[i] == 'R') str[i] = 0;
			else if (str[i] == 'G') str[i] = 1;
			else str[i] = 2;
		int ans = n;
		for (int st = 0; st < 3; st++) {
			for (int i = 0; i < n; i++) ax[i] = 0;
			int now = st;
			int acu = 0;
			for (int i = 0; i < k; i++) {
				// printf ("str[%d] = %d\n", i, str[i]);
				ax[i] = str[i] != now;
				acu += ax[i];
				now++;
				if (now == 3) now = 0;
			}
			ans = min (ans, acu);

			for (int i = k; i < n; i++) {
				// printf (" i = %d, acu = %d\n", i, acu);
				ax[i] = str[i] != now;
				acu -= ax[i-k];
				acu += ax[i];
				now++;
				if (now == 3) now = 0;
				ans = min (ans, acu);
				// printf (" i = %d, acu = %d\n", i, acu);
			}
		}

		printf ("%d\n", ans);
	}

	return 0;
}
