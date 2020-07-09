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

using pp = pair<pii, int>;

int n;
set<pp> rig;
vector<pp> lft;
vector<pii> a;
vector<int> ax1, ax2, b;

int main () {
	scanf ("%d", &n);
	ll total = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		total += x;
		a.push_back ({x, i});
		ax1.push_back (x);
	}
	sort (a.begin(), a.end(), greater<pii>());
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		total -= x;
		ax2.push_back (x);
	}
	sort (ax2.begin(), ax2.end());
	b = ax2;
	sort (b.begin(), b.end(), greater<int>());
	if (total) {
		printf ("NO\n");
		exit (0);
	} else {
		vector<pair<pii, int>> ans;
		while (len (a) > 1) {
			while (!a.empty()) {
				pii now = a.back();
				a.pop_back();
				if (now.x < b.back())
					rig.insert ({{now.x, b.back()}, now.y});
				else if (now.x > b.back())
					lft.push_back ({{now.x, b.back()}, now.y});
				b.pop_back();
			}
		}
		reverse (lft.begin(), lft.end());
		while (len (rig) and len (lft)) {
			auto pR = *rig.begin();
			auto pL = lft.back();
			rig.erase (rig.begin());
			lft.pop_back ();
			int d = min (pR.x.y - pR.x.x, pL.x.x - pL.x.y);
			d = min (d, (pL.x.x - pR.x.x)/2);
			// printf ("d = %d\n", d);
			if (d < 0 or pR.x.x >= pL.x.x) {
				printf ("NO\n");
				exit (0);
			}
			pR.x.x+=d;
			pL.x.x-=d;
			if (pR.x.x != pR.x.y)
				rig.insert (pR);
			if (pL.x.x != pL.x.y)
				lft.push_back (pL);
			ans.push_back ({{pR.y, pL.y}, d});
		}
		printf ("YES\n");
		printf ("%d\n", len (ans));
		for (auto p : ans) {
			printf ("%d %d %d\n", p.x.x, p.x.y, p.y);
			ax1[p.x.x-1] += p.y;
			ax1[p.x.y-1] -= p.y;
		}
		sort (ax1.begin(), ax1.end());
		for (int i = 0; i < len (ax1); i++) {
			// printf ("ax1[%d] = %d\n", i, ax1[i]);
			assert (ax1[i] == ax2[i]);
		}
	}

	return 0;
}