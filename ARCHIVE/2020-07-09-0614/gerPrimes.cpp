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
class MyNumPunct : public std::numpunct<char>
{
protected:
    virtual char do_thousands_sep() const { return '.'; }
    virtual std::string do_grouping() const { return "\03"; }
};


const int  P = (1<<30);

bitset<P> not_prime;
vector<int> primes;

int main () {
	cout.imbue (locale(locale::classic(), new MyNumPunct ) );
	for (int i = 2; i*i < P; i++)
		if (not_prime[i] == 0) 
			for (int j = i*i; j < P; j+=i)
				not_prime[j] = 1;
	for (int i = 2; i < P; i++)
		if (not_prime[i] == 0) primes.push_back (i);
	printf ("ready!\n");


	for (int i = 5; i <= 60; i++) {
		cout << i << ", " << (1LL<<i) << ", ";
		vector<ll> ax;
		for (ll j = 1LL<<i; j >= 0 and len (ax) < 5; j--) {
			ll val = j;
			bool prime = true;
			if (i == 1) continue;
			for (int p : primes) {
				if (p*1LL*p > val) break;
				if (val%p == 0) {
					prime = false;
					break;
				}
			}
			if (prime)
				ax.push_back (j);
		}
		for (ll j = 1LL<<i; len (ax) < 10; j++) {
			ll val = j;
			bool prime = true;
			if (i == 1) continue;
			for (int p : primes) {
				if (p*1LL*p > val) break;
				if (val%p == 0) {
					prime = false;
					break;
				}
			}
			if (prime)
				ax.push_back (j);
		}
		sort (ax.begin(), ax.end());
		for (ll v : ax)
			cout << v << ", ";
		putchar ('\n');
	}

	// while (true) {
	// 	ll l, r;
	// 	scanf ("%lld %lld", &l, &r);
	// 	for (ll i = l; i <= r; i++) {
	// 		ll val = i;
	// 		bool prime = true;
	// 		if (i == 1) continue;
	// 		for (int p : primes) {
	// 			if (p*1LL*p > val) break;
	// 			if (val%p == 0) {
	// 				prime = false;
	// 				break;
	// 			}
	// 		}
	// 		if (prime)
	// 			cout << i << '\n';
	// 	}
	// }


	return 0;
}
