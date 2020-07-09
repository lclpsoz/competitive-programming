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
	set<int> conj;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		conj.insert (a[i]);
	}
	vector<int> vec;
	for (int v : conj)
		vec.push_back (v);

	int st = max (0, len (vec)/2 - 1000);
	int en = min (len (vec)-1, len(vec)/2 + 1000);
	for (int i = st; i <= en; i++)
		mx = max (mx, eval (vec[i]));

	printf ("%d\n", mx);

	return 0;
}
