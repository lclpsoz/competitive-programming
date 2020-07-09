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
vector<pii> vec;
vector<vector<pii>> ans;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back ({x, i+1});
	}
	sort (vec.begin(), vec.end());
	
	ans.push_back (vec);
	for (int i = 1; i < len (vec); i++) {
		if (vec[i].x == vec[i-1].x) {
			swap (vec[i], vec[i-1]);
			ans.push_back (vec);
		}
		if (len (ans) == 3)
			break;
	}
	if (len (ans) < 3)
		printf ("NO\n");
	else {
		printf ("YES\n");
		for (auto &vv : ans) {
			for (int i = 0; i < len (vv); i++) {
				if (i) putchar (' ');
				printf ("%d", vv[i].y);
			}
			putchar ('\n');
		}
	}

	return 0;
}
