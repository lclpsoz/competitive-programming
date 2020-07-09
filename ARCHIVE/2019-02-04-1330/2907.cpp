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

const int N = 1e5+10;

int n;
int a[N], b[N];
vector<pt> points, vecs;
int cross (pt x, pt y) {
	return (x.x*y.y - x.y*y.x);
}

void build () {
	int j, k;
	j = 1, k = 1;
	for (int i = 0; i < n; i++) {
		j = max (i+1, j);
		while (j < n and cross (vec[i], vec[i+1]) > 0) ++j;
		--j; j = max (i+1, j);
		a[i] = j;
		while (k < n and cross (vec[i], vec[k]) == 0) ++k;
		b[i] = k;
	}
}



int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		points.push_back ({x, y});
	}
	for (int i = 0; i < n; i++) {
		if (i == n-1)
			vecs.push_back ({points[0] - points[i]});
		else
			vecs.push_back ({points[i+1] - points[i]});
	}
	
	build ();

	return 0;
}
