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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using pp = pair<ll, ll>;

const int N = 1e5 + 10;

int m;
pp dp[N];
bool not_prime[N];
vector<int> primes, divisors;

int mult (int a, int b) {
	return ((a*1LL*b)%MOD);
}

int add (int a, int b) {
	return (a+b)%MOD;
}

void sieve () {
	for (int i = 2; i*i < N; i++)
		if (!not_prime[i])
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = true;
			
	for (int i = 2; i < N; i++)
		if (!not_prime[i])
			primes.push_back (i);
}

int main () {
	sieve ();
	
	scanf ("%d", &m);
	if (m == 1)
		printf ("1\n");
	else {
		for (int i = 2; i*i <= m; i++)
			if (m%i == 0) {
				divisors.push_back (i);
				if (i*i != m)
					divisors.push_back (m/i);
			}
			
			
	}

	return 0;
}
