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

const int N = 1e3 + 10;

ll bit[N], ans[N];

void add(int p, int x) {
	for(int i = p; i < N; i+=i&-i)
		bit[i] += x;
}

ll sum_prefix(int p) {
	ll ret = 0;
	for(int i = p; i > 0; i-=i&-i)
		ret += bit[i];
	return ret;
}

ll sum(int l, int r) {
	return sum_prefix(r) - sum_prefix(l-1);
}


int main () {
	int n, k;
	scanf("%d %d", &n, &k);

	int sumAll = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		sumAll += x;
		add(i, x);
	}
	if(k >= n) {
		int cycles = k/n;
		k %= n;
		for(int i = 1; i <= n; i++)
			ans[i] = sumAll*cycles;
	}
	for(int i = 1; i <= n; i++) {
		// printf("ans[%d] = %d\n", i, ans[i]);
		if(i >= k)
			ans[i] += sum(i-k+1, i);
		else {
			// printf("[%d, %d]\n", (i-k)%n + n + 1, n);
			ans[i] += sum(1, i) + sum((i-k)%n + n + 1, n);
		}
	}

	// printf("n = %d\n", n);
	for(int i = 1; i <= n; i++)
		printf("%lld%c", ans[i], " \n"[i==n]);

	return 0;
}
