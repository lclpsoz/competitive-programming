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

int n;
vector<pii> obelisk;
set<pii> clue;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		obelisk.push_back ({x, y});
	}
	for (int j = 0; j < n; j++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		clue.insert ({x, y});
	}
	
	for (pii cl : clue) {
		pii p = {obelisk[0].x+cl.x, obelisk[0].y+cl.y};
// 		printf ("p: %d %d\n", p.x, p.y);
		bool test = true;
		for (pii ob : obelisk) {
			pii target = {p.x - ob.x, p.y - ob.y};
			if (clue.count (target) == 0) {
				test = false;
				break;
			}
		}
		if (test) {
			printf ("%d %d\n", p.x, p.y);
			return 0;
		}
	}
	assert (false);
	
	return 0;
}
