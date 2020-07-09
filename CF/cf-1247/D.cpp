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

const int P = 1e5 + 10, N = 1e5 + 10;
const int A = 911382323, B = 972663749;
const int A2 = 536870849, B2 = 999999797;

ll hashing (vector<int> &vec) { 
	int a = A, a2 = A2, ret = 1, ret2 = 1;
	for (int i = 0; i < len (vec); i++) {
		// printf ("  (hashing) %d: %d\n", i, vec[i]);
		ret = (ret + (vec[i]*1LL*a)%B)%B;
		ret2 = (ret2 + (vec[i] * 1LL * a2)%B2)%B2;
		// printf ("  (hashing) %d: %d ret = %d\n", i, vec[i], ret);
		a = (a* 1LL * A)%B;
		a2 = (a2 * 1LL * A2)%B2;
	}

	return ret*1LL*ret2;
}

int n, k;
bitset<P> not_prime;
vector<int> primes;
map<ll, map<ll, int>> mp; // First is hash of primes, then hash of expoents
ll arr[N], hashPrimes[N], hashExp[N], hashExpComp[N];

void fact (int ii, int x) {
	vector<int> exp, pNow;
	// printf ("x = %d\n", x);
	for (int p : primes) {
		// printf ("x = %d, p = %d\n", x, p);
		if (p*p > x) break;
		if (x%p == 0) {
			pNow.push_back (p);
			exp.push_back (1);
			x /= p;
			while (x%p == 0) {
				exp.back()++;
				x /= p;
			}
			exp.back()%=k;
			if (exp.back () == 0) {
				exp.pop_back ();
				pNow.pop_back ();
			}
		}
	}
	if (x > 1)
		pNow.push_back (x), exp.push_back (1);
	hashPrimes[ii] = hashing (pNow);
	// printf ("HASH PRIMES = %d\n", hashing (pNow));
	hashExp[ii] = hashing (exp);

	// printf ("hP = %d, hE = %d\n", hashPrimes[ii], hashExp[ii]);
	// printf ("pNow = ");
	// for (int p : pNow)
	// 	printf ("%3d ", p);
	// putchar ('\n');
	// printf ("exp = ");
	// for (int p : exp)
	// 	printf ("%3d ", p);
	// putchar ('\n');


	for (int i = 0; i < len (exp); i++)
		exp[i] = k - exp[i];
	// printf ("expComp = ");
	// for (int p : exp)
	// 	printf ("%3d ", p);
	// putchar ('\n');
	hashExpComp[ii] = hashing (exp);
	// printf (" hCE = %d\n", hashExpComp[ii]);
	// putchar ('\n');
	mp[hashPrimes[ii]][hashExp[ii]]++;
}

int main () {
	for (int i = 2; i*i < P; i++)
		if (not_prime[i] == 0)
			for (int j = i*i; j < P; j+=i)
				not_prime[j] = 1;
	for (int i = 2; i < P; i++)
		if (not_prime[i] == 0)
			primes.push_back (i);
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		arr[i] = x;
		fact (i, x);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += mp[hashPrimes[i]][hashExpComp[i]];
		if (hashExpComp[i] == hashExp[i]) --ans;
		// printf ("%d: %lld\n", i, ans);
	}
	printf ("%lld\n", ans/2);



	return 0;
}
