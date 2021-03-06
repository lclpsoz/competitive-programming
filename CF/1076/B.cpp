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

const int P = 1e5+100;

ll n;
bool not_prime[P];
vector<int> primes;

int main () {
	not_prime[0] = not_prime[1] = true;
	for (int i = 2; i*i < P; i++) {
		if (!not_prime[i])
			for (int j = i*i; j < P; j += i)
				not_prime[j] = true;
	}
	
	for (int i = 2; i < P; i++)
		if (!not_prime[i])
			primes.push_back (i);
	
	scanf ("%lld", &n);
		
	bool isPrime = true;
	int pos;
	for (int i = 0; i < len (primes); i++)
		if (n%primes[i] == 0) {
			isPrime = false;
			pos = (primes[i]-3)/2;
			break;
		}
	
	if (isPrime)
		printf ("1\n");
	else if (n%2 == 0 or n%3 == 0)
		printf ("%lld\n", n/2);
	else
		printf ("%lld\n", (n/2)-pos);
	
	return 0;
}
