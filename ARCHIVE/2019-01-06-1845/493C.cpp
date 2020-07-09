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

const int N = 2e5+100;

int n, m;
vector<pii> vec;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back ({x, 1});
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back ({x, 2});
	}
	
	sort (vec.rbegin(), vec.rend());
	
	pii scr = {2*n, 2*m};
	pii acu = scr;
	for (int i = 0; i < len (vec); i++) {
		if (vec[i].y == 1)
			++acu.x;
		else
			++acu.y;
		if (acu.x - acu.y >= scr.x - scr.y)
			scr = acu;
	}
	
	printf ("%d:%d\n", scr.x, scr.y);
	
	

	return 0;
}
