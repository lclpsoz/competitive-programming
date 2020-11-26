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

const int N = 1e7 + 10;

int n;
int lst[N];
bool v[N];

int mdc (int a, int b){
	if (b == 0) return a;
	return mdc (b, a%b);
}

ll mmc (int a, int b) {
	return (a*1LL*b)/mdc (a,b);
}

int main () {
	scanf ("%d", &n);
	ll ans = 1e18;
	pii p = {-1, -1};
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		if (v[x] and x < ans) {
			ans = x;
			p = {lst[x], i};
		}
		lst[x] = i;
		v[x] = true;
	}
	for (int i = 1; i < N; i++) {
		int num = -1;
		for (int j = i; j < N; j+=i)
			if (num == -1 and v[j]) num = j;
			else if (num != -1 and v[j]) {
				ll mc = mmc (num, j);
				if (mc < ans) {
					ans = mc;
					p = {lst[j], lst[num]};
				} 
			}
	}
	assert (p.x != -1);
	if (p.x > p.y) swap (p.x, p.y);
	printf ("%d %d\n", p.x + 1, p.y + 1);

	return 0;
}