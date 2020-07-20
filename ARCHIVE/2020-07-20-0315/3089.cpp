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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int main () {
	int n;
	while(scanf("%d", &n), n) {
		vector<int> vec;
		for(int i = 0; i < 2*n; i++) {
			int x;
			scanf("%d", &x);
			vec.push_back(x);
		}
		int mx = -1e9;
		int mn = 1e9;
		for(int i = 0; i < n; i++) {
			vec[i] += vec[2*n-1-i];
			mn = min(vec[i], mn);
			mx = max(mx, vec[i]);
		}
		printf("%d %d\n", mx, mn);
	}

	return 0;
}
