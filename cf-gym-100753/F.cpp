#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

using u64 = uint64_t;
using u128 = __uint128_t;

const int P = 1e7 + 100;

bitset<P> not_prime;
vi primes;

ll gcd(ll x, ll y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

ll modMul(ll x, ll y, ll m) {
	return (((u128)x)*y)%m;
}

ll pollard(ll n) {
	int i = 0, k = 2, d;
	ll x = 3, y = 3;
	while(++i) {
		x = (modMul(x, x, n) + n - 1)%n;
		d = gcd(abs(y-x), n);
		if(d != 1 and d != n) return d;
		if(i == k) y = x, k *= 2;
	}
}

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)(result) * base % mod;
        base = (u128)(base) * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)(x) * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	for(int i = 2; i*i < P; i++)
		if(!not_prime[i])
			for(int j = i*i; j < P; j+=i)
				not_prime[j] = 1;

	// int cnt_prime = 0;
	for(int i = 2; i < P; i++) {
		// cnt_prime += !not_prime[i];
		if(!not_prime[i])
			primes.push_back(i);
	}
	// cout << cnt_prime << '\n';

	ll n;
	cin >> n;

	vi exp;
	
	int p = 0;
	while(n > 1) {
		// cout << "n = " << n << '\n';
		ll fact = -1;
		if(n > 1e14) {
			fact = n;
			while(!MillerRabin(fact)) {
				if(fact > 1e14)
					fact = pollard(fact);
				else {
					for(int prime : primes)
						if(fact%prime == 0) {
							fact = prime;
							break;
						}
				}
				// cout << "fact = " << fact << '\n';
			}
			
		} else {
			while(p < LEN(primes) and n%primes[p]) ++p;
			if(p < LEN(primes)) fact = primes[p];
		}
		if(fact == -1) fact = n;
		exp.push_back(0);
		while(n%fact == 0) {
			n /= fact;
			exp.back()++;
		}
	}
	ll ans = 1;
	for(int v : exp)
		ans *= v+1;
	cout << ans << '\n';

	return 0;
}
