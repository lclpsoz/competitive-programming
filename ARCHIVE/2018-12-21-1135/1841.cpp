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

const int N = 1e7+10, P = 1e7+100;

ll n;
bool not_prime[P];
vector<int> primes;
int arr[N], bit[N];

int powMod (int b, int p) {
    int r = 1;
    while (p) {
        if (p&1)
            r = mod (b*1LL*r);
        b = mod (b*1LL*b);
        p >>= 1;
    }
    
    return r;
}

int invMod (int v) {
    return powMod (v, MOD-2);
}

void upd (int p) {
    int val = mod (invMod (arr[p]) * 1LL * (arr[p]+1));
    ++arr[p];
    for (; p < N; p+=p&-p)
        bit[p] = mod (bit[p]*1LL*val);
}

int qry (int p) {
    int r = 1;
    for (; p >= 1; p-=p&-p)
        r = mod (r*1LL*bit[p]);
    
    return r;
}

void sieve () {
	int i = 2;
	for (; i*i < P; i++)
		if (!not_prime[i]) {
			primes.push_back (i);
			for (int j = i*i; j < P; j+=i)
				not_prime[j] = true;
		}
	for (; i < P; i++)
		if (!not_prime[i])
			primes.push_back (i);
}

int main () {
	sieve ();
    for (int i = 0; i < N; i++)
        bit[i] = arr[i] = 1;
        
    int p;
    scanf ("%lld", &n);
    int pos = 0;
    while (n > 1 and pos < len (primes)) {
        while (n%primes[pos] == 0) {
            upd (primes[pos]);
            n /= primes[pos];
        }
        ++pos;
    }

    while (scanf ("%d", &p) != EOF) {
        printf ("%d\n", qry (p-1));
        upd (p);
    }

	return 0;
}
