#include<bits/stdc++.h>
using namespace std;

// -----------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// -----------

using T = ll;

struct pt {
	T x, y;
};

using polygon = vector<pt>;
using polSides = pair<polygon, polygon>;

polygon pols[15];

polSides getSides (polygon &pol, int h, int xMin, int xMax) {
	polSides sides;
	int i = 0;
	// Left
	sides.x.push_back (pol[0]);
	
	// Right
	while (pol[i].y == 0) ++i;
	--i;
	while (pol[i].y != h)
		sides.y.push_back (pol[i++]);
	sides.y.push_back (pol[i++]);
	
	while (i < len (pol) and pol[i].y == h) ++i;
	--i;
	// Left
	while (i < len (pol))
		sides.x.push_back (pol[i++]);
	
	// Put it in x == 0
	for (auto &p : sides.x)
		p.x -= xMin;
	for (auto &p : sides.y)
		p.x -= xMax;
	
	return sides;
}

// Sweep line
ld maxInter (polygon &l, polygon &r) {
	int 
}

int main () {
	int n, k;
	while (scanf ("%d %d", &n, &k) != EOF) {
		int h = -1;
		for (int i = 0; i < n; i++) {
			int k;
			scanf ("%d", &k);
			while (k--) {
				int x, y;
				scanf ("%d %d", &x, &y);
				pols[i].push_back ({x, y});
				h = max (h, y);
			}
			
		}
	}
    
    return 0;
}
