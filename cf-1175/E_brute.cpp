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

int n, m;
vector<pii> segs;
bool ax[N];

bool check (int l, int r, int msk) {
	for (int i = l; i <= r; i++) ax[i] = false;
	for (int i = 0; i < n; i++)
		if (msk&(1<<i))
			for (int j = max (l, segs[i].x); j <= min (r, segs[i].y); j++) ax[j] = true;
	for (int i = l; i <= r; i++) if (!ax[i]) return false;
	return true;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf ("%d %d", &l, &r);
		segs.push_back ({l+1, r});
	}
	sort (segs.begin(), segs.end());
	vector<int> masks;
	for (int i = 1; i < (1<<n); i++) masks.push_back (i);
	sort (masks.begin (), masks.end(), [&] (int x, int y) {
		return __builtin_popcount (x) < __builtin_popcount (y);
	});

	while (m--) {
		int l, r;
		scanf ("%d %d", &l, &r);
		++l;
		bool ans = false;
		for (int msk : masks)
			if (check (l, r, msk)) {
				printf ("%d\n", __builtin_popcount (msk));
				ans = true;
				break;
			}
		if (!ans)
			printf ("-1\n");
	}

	return 0;
}
