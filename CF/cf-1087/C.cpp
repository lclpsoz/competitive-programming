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

pii a[5];
set<pii> ans;

void pathHor (int i, int j) {
	pii now = a[i], tar = a[j];
	while (now.x != tar.x) {
		if (now.x < tar.x) {
			++now.x;
			ans.insert (now);
		} else {
			--now.x;
			ans.insert (now);
		}
	}
	while (now.y != tar.y) {
		if (now.y < tar.y) {
			++now.y;
			ans.insert (now);
		} else {
			--now.y;
			ans.insert (now);
		}
	}
}

void vert (pii now, pii target) {
	while (now.y > target.y) {
		now.y--;
		ans.insert (now);
	}
	while (now.y < target.y) {
		now.y++;
		ans.insert (now);
	}
}

void prt () {
	printf ("%d\n", len (ans));
	for (pii p : ans)
		printf ("%d %d\n", p.x, p.y);
	exit (0);
}

int main () {
	for (int i = 0; i < 3; i++) {
		scanf ("%d %d", &a[i].x, &a[i].y);
		ans.insert (a[i]);
	}
	sort (a, a+3);
	// 1st scenario
	if (	(a[0].y >= a[1].y and a[1].y >= a[2].y) or
			(a[0].y <= a[1].y and a[1].y <= a[2].y)		) {
		pathHor (0, 1);
		pathHor (1, 2);
		prt ();
	}
	// 2nd scenario
	else {
		if (a[0].y < a[2].y) swap (a[0], a[2]);
		// Now a[0].y >= a[2].y
		
		if (a[1].y > a[0].y) { 
			pathHor (0, 2);
			vert (a[1], a[0]);
		} else {
			pathHor (2, 0);
			vert (a[1], a[2]);
		}
		
		prt();
	}
	
	assert (false);
	
	return 0;
}
