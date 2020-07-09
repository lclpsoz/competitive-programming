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

const int N = 110;

int n;
pii a[N];
bool open[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d %d", &a[i].x, &a[i].y);

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				if (a[i].y == a[j].x and !open[j]) {
					open[j] = true;
					++ans;
				}
	printf ("%d\n", n-ans);
				
				
	return 0;
}
