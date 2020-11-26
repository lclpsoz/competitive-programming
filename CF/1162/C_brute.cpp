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

const int N = 1e5 + 10;

int n, k;
int a[N];
int st[N], en[N];
vector<int> vec;

int main () {
	scanf ("%d %d", &n, &k);
	en[0] = en[n+1] = 1e8;
	for (int i = 1; i <= n; i++)
		st[i] = n+10;
	for (int i = 1; i <= k; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back (x);
	}
	// for (int i = 1; i <= n; i++) vec.push_back (en[i]);
	// sort (vec.begin(), vec.end());
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (abs(i-j) > 1) continue;
			bool other = (i == j);
			bool ok = true;
			for (int p = 0; p < k; p++)
				if (!other and vec[p] == i) other = true;
				else if (other and vec[p] == j) ok = false;
			printf ("%d %d %d\n", i, j, ok);
			ans += ok;
		}
	printf ("%lld\n", ans);
	
	return 0;
}
