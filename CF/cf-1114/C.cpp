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

const int N = 1e6+100;

using pp = pair<ll, int>;

bool not_prime[N];
vector<int> primes;

void sieve () {
	int i = 2;
	for (; i*i < N; i++)
		if (!not_prime[i])
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = true;
	i = 2;
	for (; i < N; i++)
		if (!not_prime[i])
			primes.push_back (i);
}

vector<pp> func (ll x) {
	vector<pp> fact;
	for (int p : primes) {
		while (x % p == 0) {
			if (fact.empty() or fact.back().x != p)
				fact.push_back ({p, 0});
			fact.back().y++;
			x /= p;
		}
		if (x == 1) break;
	}
	if (x > 1)
		fact.push_back ({x, 1});
		
	return fact;
}

int main () {
	ll n, b;
	scanf ("%lld %lld", &n, &b);
	
	sieve();
// 	printf ("%d\n", primes[0]);
	vector<pp> fact = func (b);
	
	ll ans = 1e18;
	for (pp f : fact) {
//  		printf ("%lld %d\n", f.x, f.y);
		ll now = 0;
		ll aux = n;
		while (aux >= f.x) {
			aux /= f.x;
			now += aux;
		}
		ans = min (ans, now/f.y);
	}
	
	printf ("%lld\n", ans);

	return 0;
}
