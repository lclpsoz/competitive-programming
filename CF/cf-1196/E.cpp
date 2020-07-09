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

int MID = 1e9/2;

int q;
vector<pii> ans;
set<pii> black, white;


int main () {
	scanf ("%d", &q);
	while (q--) {
		int b, w;
		ans.clear();
		white.clear();
		black.clear();
		scanf ("%d %d", &b, &w);
		int mn = min (b, w);
		for (int qqq = 0; qqq < 2*mn; qqq++) {
			int qq = -qqq;
			int x = MID, y = MID+qq;
			ans.push_back ({x, y});
			if ((x+y)&1) {// black
				for (int i = -1; i <= 1; i++)
					for (int j = -1; j <= 1; j++)
						if ((i == 0 or j == 0) and (j or i)) {
							// printf ("%d %d\n", i, j);
							white.insert ({x+i, y+j});
						}
			} else
				for (int i = -1; i <= 1; i++)
					for (int j = -1; j <= 1; j++)
						if ((i == 0 or j == 0) and (j or i))
							black.insert ({x+i, y+j});
		}
		if (len (white) >= w and len (black) >= b) {
			printf ("YES\n");
			w -= mn, b -= mn;
			for (auto p : ans)
				black.erase (p), white.erase (p);
			// printf ("w = %d, b = %d, lwnW = %d\n", w, b, len (white));
			while (w-- and len (white)) {
				ans.push_back (*white.begin());
				white.erase (white.begin());
			}
			while (b-- and len (black)) {
				ans.push_back (*black.begin());
				black.erase (black.begin());
			}
			assert (b <= 0 and w <= 0);
			for (auto p : ans)
				printf ("%d %d\n", p.x, p.y);
		} else
			printf ("NO\n");
	}

	return 0;
}
