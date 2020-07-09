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

const int N = 3e5 + 10;

int n;
int a[N];
vector<pii> vec;
int mini[N]; // For size of the segment, j-i = 1..n-1

bool check (int x) {
	for (int i = 1; i < n; i++) {
		// printf ("i = %d,x = %d, %d vs %d\n", i, x, x*i, mini[i]);
		if (x*1LL*i > mini[i])
			return false;
	}
	return true;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		vec.push_back ({a[i], i});
	}
	int lst = 0;
	sort (vec.begin(), vec.end());
	for (auto pp : vec) {
		int val = pp.x;
		int pos = pp.y;
		// printf ("lst = %d, %d: %d %d\n", lst, val, pos, n-pos-1);
		for (int i = lst+1; i <= max (pos, n-pos-1); i++) {
			mini[i] = val;
			lst = max (pos, n-pos-1);
		}
	}
	int l = 0, r = 1000000000;
	while (l < r) {
		int md = (l+r+1)/2;
		if (check (md))
			l = md;
		else
			r = md-1;
	}
	printf ("%d\n", l);

	return 0;
}
