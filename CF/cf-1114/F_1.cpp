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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using mp = unordered_map<int, ll>;

const int N = 4e5+100;

int n, q;
bool not_prime[310];
vector<int> primes;
mp BIT[65][2];

void sieve () {
	for (int i = 2; i*i <= 300; i++)
		if (!not_prime[i])
			for (int j = i*i; j <= 300; j+=i)
				not_prime[j] = true;
			
	for (int i = 2; i <= 300; i++)
		if (!not_prime[i])
			primes.push_back (i);
}

void update (mp &ft, int p, int v) {
	for (; p < N; p+=p&-p)
		ft[p] += v;
}

void update (mp &b1, mp &b2, int l, int r, int v) {
	update (b1, l, v);
	update (b1, r+1, -v);
	update (b2, l, v * (l-1));
	update (b2, r+1, -v * (r));
}

ll query (mp &ft, int p) {
	ll sum = 0;
	for (; p > 0; p -= p&-p)
		sum += ft[p];
	return sum;
}

ll query (mp &b1, mp &b2, int p) {
	return query (b1, p) * p - query (b2, p);
}

ll query (mp &b1, mp &b2,  int l, int r) {
	return query (b1, b2, r) - query (b1, b2, l-1);
}

int powMod (int b, ll p) {
	if (p < 0) return 0; // BE CAREFUL!!!
	int ret = 1;
	while (p) {
		if (p&1) ret = mod (ret * 1LL * b);
		p >>= 1;
		b = mod (b * 1LL * b);
	}
	
	return ret;
}

void upd (int l, int r, int x) {
	for (int j = 0; j < len (primes); j++) {
		int p = primes[j];
		int e = 0;
		while (x%p == 0) {
			x /= p;
			++e;
		}
		if (e) update (BIT[j][0], BIT[j][1], l, r, e);
	}
}

int qry (int l, int r) {
	int ret = 1;
// 	printf ("[%d, %d]\n", l, r);
	for (int i = 0; i < len (primes); i++) {
		ll k = query (BIT[i][0], BIT[i][1], l, r);
// 		printf ("%d: %d\n", primes[i], k);
		ret = mod (ret * 1LL * mod (powMod (primes[i], k) - 
									powMod (primes[i], k-1)));
// 		printf ("ret: %d\n", ret);
	}
	
	return ret;
}

int main () {
	sieve();
	scanf ("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		upd (i, i, x);
	}
	
	char arr[15];
	int l, r, v;
	while (q--) {
		scanf ("%s %d %d", arr, &l, &r);
		if (l > r) swap (l, r);
		if (arr[0] == 'M') {
			scanf ("%d", &v);
			upd (l, r, v);
		} else
			printf ("%d\n", qry (l, r));
	}
	

	return 0;
}