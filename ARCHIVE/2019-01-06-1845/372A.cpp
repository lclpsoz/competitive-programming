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
vector<int> vec;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec.emplace_back (x);
	}
	sort (vec.begin(), vec.end());
	int ans = n, posSt = ((n-1)/2);
	int pos = posSt;
	for (int i = len(vec)-1; i > posSt and pos >= 0; i--) {
		while (pos >= 0 and vec[i]/2 < vec[pos]) --pos;
		if (pos >= 0) {
			--ans;
			pos--;
		}
	}		
	printf ("%d\n", ans);

	return 0;
}