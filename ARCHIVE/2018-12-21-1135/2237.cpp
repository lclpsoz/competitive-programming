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

vector<int> st, en;
set<vector<int>> verif;

int main () {
	for (int i = 0; i < 8; i++) {
		int x;
		scanf ("%d", &x);
		st.push_back (x);
	}
	for (int i = 0; i < 8; i++) {
		int x;
		scanf ("%d", &x);
		en.push_back (x);
	}
	
	set<pair<int, vector<int>>> dij;
	dij.insert ({0, st});
	while (!dij.empty() and dij.begin()->y != en) {
		int w = dij.begin()->x;
		vector<int> v = dij.begin()->y;
		dij.erase (dij.begin());
		if (verif.count (v) == 1)
			continue;
		verif.insert (v);
		
		for (int i = 0; i < 7; i++) {
			if (i == 3) continue;
			swap (v[i], v[i+1]);
			dij.insert ({w+v[i]+v[i+1], v});
			swap (v[i], v[i+1]);
		}
		
		for (int i = 0; i < 4; i++) {
			swap (v[i], v[i+4]);
			dij.insert ({w+v[i]+v[i+4], v});
			swap (v[i], v[i+4]);
		}
	}
	
	printf ("%d\n", dij.begin()->x);

	return 0;
}
