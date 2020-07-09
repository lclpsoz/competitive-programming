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

int total, q;
vector<pii> leaks;
multiset<int, greater<int>> st;

int main () {
	scanf ("%d %d", &total, &q);
	while (q--) {
		int t, h;
		scanf ("%d %d", &t, &h);
		leaks.push_back ({t, h});
	}
	sort (leaks.begin (), leaks.end(), greater<pii>());

	int qnt = 0;
	ld tNow = 0, water = total;
	while (cmp (water) == 1) {
		// printf ("tNow = %.2Lf\twater = %.4Lf\n", tNow, water);
		ld tNextNew = INF, tNextOld = INF, tEmpty = INF;
		if (qnt)
			tEmpty = tNow + water/qnt;
		if (!leaks.empty())
			tNextNew = leaks.back().x;
		if (!st.empty()) {
			tNextOld = tNow + (water - *st.begin())/qnt;
			while (cmp (tNextOld, tNow) == -1) {
				st.erase(st.begin());
				--qnt;
				if (!st.empty())
					tNextOld = tNow + (water - *st.begin())/qnt;
				else
					tNextOld = INF;
			}
		}
		
		if (cmp (tEmpty, tNextNew) <= 0 and cmp (tEmpty, tNextOld) <= 0) {
			tNow = tEmpty;
			break;
		} else if (cmp (tNextNew, tNextOld) < 0) {
			int h = leaks.back().y;
			leaks.pop_back();
			// printf ("tNow = %.2Lf\tNEW LEAK, OUT IN %d!\n", tNextNew, h);
			if (cmp (h, water) >= 0)
				continue;
			st.insert (h);
			if (qnt)
				water -= (tNextNew - tNow)*qnt;
			++qnt;
			tNow = tNextNew;
		} else {
			// printf ("tNow = %.2Lf\tREMOVING LEAK!\n", tNextOld);
			st.erase (st.begin());
			if (qnt)
				water -= (tNextOld - tNow)*qnt;
			--qnt;
			tNow = tNextOld;
		}
	}

	if (tNow > 1e10)
		printf ("-1\n");
	else
		printf ("%.10Lf\n", tNow);


	return 0;
}
