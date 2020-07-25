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

int t;
int n, a[1010];

int main () {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int total = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			total += a[i];
		}
		int ans = 0;
		int prev = 0;
		int l = 0, r = n-1;
		int sumL = 0, sumR = 0;
		while(total) {
			int ax = 0;
			while(total and ax <= prev) {
				ax += a[l];
				total -= a[l];
				++l;
			}
			sumL += ax;
			prev = ax;
			++ans;
			if(total == 0) break;
			ax = 0;
			while(total and ax <= prev) {
				ax += a[r];
				total -= a[r];
				--r;
			}
			sumR += ax;
			prev = ax;
			++ans;
		}
		printf("%d %d %d\n", ans, sumL, sumR);
	}

	return 0;
}
