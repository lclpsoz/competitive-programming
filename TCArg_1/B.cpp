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

const int N = 3e5;

ll fat[N];
ll n, m;

int solve() {
	ll ret = n*fat[n];
	if(n > 1)
		ret += fat[n];
	for(int i = 1; i < n-1; i++)
		ret = (ret + (((n-i)*fat[i+1])%m)*fat[n-i])%m;
	return ret%m;
}

int main () {
	scanf("%lld %lld", &n, &m);
	fat[0] = fat[1] = 1;
	for(int i = 2; i < N; i++)
		fat[i] = (fat[i-1]*i)%m;
	printf("%d\n", solve());

	return 0;
}
