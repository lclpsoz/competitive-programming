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

void no () {
	printf ("NO\n");
	exit (0);
}

vector<int> vec;

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back (x);
	}
	if (m == 0) {
		printf ("YES\n");
		exit (0);		
	}
	sort (vec.begin(), vec.end());
	if (vec[0] == 1 or vec[m-1] == n) no();
	for (int i = 1; i < m-1; i++)
		if (vec[i-1] == vec[i]-1 and vec[i+1] == vec[i]+1)
			no ();
	printf ("YES\n");

	return 0;
}
