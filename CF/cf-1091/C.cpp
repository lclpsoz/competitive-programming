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

const int N = 1e9+100, V = 1e5+10;

int n;
int not_prime[V];
set<ll> st;

int main () {
	scanf ("%d", &n);
// 	st.clear ();
// 	memset (not_prime, 0, sizeof not_prime);
	st.insert ((n*1LL*(n+1))/2);
	st.insert (1);
	for (ll i = 2; i*i <= n; i++)
		if (n%i == 0) {
			int ax = n/i, qnt;
			if (ax != i) {
				qnt = n/ax;
				ll val = (1+(n-ax+1));
				ll sum = val*1LL*(qnt/2);
				if (qnt&1)
					sum += val/2;
				st.insert (sum);
			}
			qnt = n/i;
			ll val = (1+(n-i+1));
			ll sum = val*1LL*(qnt/2);
			if (qnt&1)
				sum += val/2;
			st.insert (sum);
		}
	
	for (ll v : st)
		printf ("%lld ", v);
	putchar ('\n');
	
	return 0;
}
