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

const ld EPS = 1e-6;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const ld INF = 1e18;

ld water;
int q;
vector<pii> newLeaks;
multiset<int, greater<int>> oldLeaks;

int main () {
	scanf ("%Lf %d", &water, &q);
	bool ok = false;
	while (q--) {
		int t, h;
		scanf ("%d %d", &t, &h);
		newLeaks.push_back ({t, h});
		if (h == 0) ok = true;
	}
	sort (newLeaks.begin(), newLeaks.end(), greater<pii>());

	if (!ok) {
		printf ("-1\n");
		exit (0);
	}

	ld tNow = 0;
	int qnt = 0;
	while (cmp (water) == 1) {
		ld tEmpty = INF, tNew = INF, tOld = INF;
		if (qnt)
			tEmpty = tNow + water/qnt;
		if (!newLeaks.empty())
			tNew = newLeaks.back().x;
		if (!oldLeaks.empty()) {
			tOld = tNow + (water - (ld)*oldLeaks.begin())/qnt;
			assert (cmp (tOld, tNow) >= 0);
		}
		printf ("%3.2Lf:: water: %Lf | %Lf | %Lf | %Lf\n", tNow, water, tEmpty, tNew, tOld);
		if (cmp (tEmpty, tNew) <= 0 and cmp (tEmpty, tOld) <= 0) {
			tNow = tEmpty;
			break;
		} else if (cmp (tNew, tOld) <= 0) {
			int h = newLeaks.back().y;
			newLeaks.pop_back ();
			if (cmp (h, water) >= 0) continue;
			water -= (tNew - tNow)*qnt;
			tNow = tNew;
			if (cmp (h, water) >= 0) continue;
			oldLeaks.insert (h);
			++qnt;
		} else {
			// ld ax = (tOld - tNow)*qnt;
			// water -= (tOld - tNow)*qnt;
			while (!oldLeaks.empty() and cmp ((ld)*oldLeaks.begin(), water) >= 0) {
				oldLeaks.erase (oldLeaks.begin());
				--qnt;
			}
			water -= (tOld - tNow)*qnt;
			// assert (ax == (tOld - tNow)*qnt);
			tNow = tOld;
		}
	}
	printf ("%.10Lf\n", tNow);

	return 0;
}
