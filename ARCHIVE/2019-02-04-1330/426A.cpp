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

int n, s;

int main () {
	scanf ("%d %d", &n, &s);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back (x);
	}
	sort (vec.begin(), vec.end());
	int sum = 0;
	for (int i = 0; i < n-1; i++)
		sum += vec[i];
	if (sum <= s)
		printf ("YES\n");
	else
		printf ("NO\n");
	
	return 0;
}
