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
int ar[1010];
int ok[1010];

int main () {
	scanf ("%d %d", &n, &k);
	queue<int> all;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &ar[i]);
		all.push (i);
	}
	
	int t = 0;
	int m = 0;
	queue<pii> proc;
	while (len (proc) < k and len (all)) {
		proc.push ({1, all.front()});
		all.pop();
	}
	int ans = 0;
	while (m < n) {
		int d = ((100.0*m)/n)+0.5;
		queue<pii> ax;
		// printf ("t = %d, d = %d\n", t++, d);
		while (!proc.empty()) {
			int a = proc.front().x, b = proc.front().y;
			// printf ("  id = %d, test = %d\n", b, a);
			proc.pop();
			if (a == d) {
				ok[b] = true;
				// printf ("  ------- INTERESTING! ------\n");
			}
			if (a == ar[b]) {
				++m;
				if (len (all)) {
					ax.push ({1, all.front()});
					all.pop();
				}
			}
			else
				ax.push ({++a, b});
		}
		proc.swap (ax);
	}
	for (int i = 1; i <= n; i++) ans += ok[i];
	printf ("%d\n", ans);

	return 0;
}
