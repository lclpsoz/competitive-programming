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

int n;
int arr[100100];

int main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int l = 0, r = n-1;
	ll pb, pm;
	pb = pm = 0;
	ll ans = 0;
	while(l <= r) {
		if(pb > pm)
			pm += arr[r--];
		else
			pb += arr[l++];
		if(pm == pb)
			ans = pm;
	}
	printf("%lld\n", ans);

	return 0;
}
