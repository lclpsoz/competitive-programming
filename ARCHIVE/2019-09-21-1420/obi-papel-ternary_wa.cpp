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

const int N = 1e5 + 10;

int n;
int a[N];

int eval (int h) {
	int ret = 1;
	bool sq = false;
	for (int i = 0; i < n; i++) {
		if (a[i] > h) sq = true;
		else {
			ret += sq;
			sq = false;
		}
	}
	if (sq) ++ret;
	return ret;
}

int main () {
	scanf ("%d", &n);
	int mx = -1;
	set<int> st;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		st.insert (a[i]);
		mx = max (mx, a[i]);
	}
	vector<int> vec;
	for (int v : st)
		vec.push_back (v);
	// for (int i = 1; i <= mx; i++)
	// 	printf ("%d: %d\n", i, eval (i));

	int l = 0, r = len (vec);
	while (l < r - 5) {
		int tl = ((ll)2*l+r) / 3;
		int tr = ((ll)l + 2*r) / 3;
		// printf ("%d %d | %d %d | %d %d\n", l, r, tl, tr, eval (tl), eval (tr));
		int eTl = eval (vec[tl]);
		int eTr = eval (vec[tr]);
		if (eTl > eTr)
			r = tr;
		else if (eTl == eTr)
			r = tr, l = tl;
		else
			l = tl;
		
	}
	mx = -1;
	while (l <= r)
		mx = max (mx, eval (vec[l++]));

	printf ("%d\n", mx);

	return 0;
}
