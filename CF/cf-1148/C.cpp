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

const int N = 3e5 + 100;

int n;
int a[N], pos[N];

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		pos[a[i]] = i;
	}

	vector<pii> ans;
	for (int i = 2; i < n; i++)
		if (pos[i] != i) {
			if (pos[i] != 1 and pos[i] != n) {
				if (pos[i] <= n/2) {
					pos[a[n]] = pos[i];
					swap (a[pos[i]], a[n]);
					ans.push_back ({pos[i], n});
					pos[i] = n;
				} else {
					pos[a[1]] = pos[i];
					swap (a[pos[i]], a[1]);
					ans.push_back ({pos[i], 1});
					pos[i] = 1;
				}
			}

			if (i > n/2 and pos[i] == n) {
				swap (a[1], a[n]);
				ans.push_back ({1, n});
			}
			if (i <= n/2 and pos[i] == 1) {
				swap (a[1], a[n]);
				ans.push_back ({1, n});
			}

			if (i > n/2) {
				swap (a[1], a[i]);
				ans.push_back ({1, i});
			} else {
				swap (a[n], a[i]);
				ans.push_back ({n, i});
			}
			pos[a[1]] = 1;
			pos[a[n]] = n;
			pos[a[pos[i]]] = pos[i];
			pos[i] = i;
		}
	if (a[1] != 1)
		ans.push_back ({1, n});
	printf ("%d\n", len (ans));
	for (auto p : ans)
		printf ("%d %d\n", p.x, p.y);

	return 0;
}
