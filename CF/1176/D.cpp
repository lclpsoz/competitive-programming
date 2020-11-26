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

const int P = 3e6 + 10;

int n;
int sqN = sqrt(2e5 + 100);
bool not_prime[P];
vector<int> ans;
map<int, int> mt;
vector<int> primes;

int bigDiv (int x) {
	for (int v : primes)
		if (x%v == 0) return x/v;
}

int getPrimePos (int x) {
	return (lower_bound (primes.begin(), primes.end(), x) - primes.begin() + 1);
}

int main () {
	for (int i = 2; i*i < P; i++)
		if (!not_prime[i])
			for (int j = i*i; j < P; j+=i)
				not_prime[j] = true;
	for (int i = 2; i < P; i++)
		if (!not_prime[i])
			primes.push_back (i);
	

	scanf ("%d", &n);
	vector<int> vec;
	for (int i = 0; i < 2*n; i++) {
		int x;
		scanf ("%d", &x);
		mt[x]++;
		vec.push_back (x);
	}
	sort (vec.begin(), vec.end());
	while (!vec.empty()) {
		int x = vec.back(); vec.pop_back ();
		if (mt[x]) {
			// printf ("x = %d\n", x);
			if (!not_prime[x]) {
				int p = getPrimePos (x);
				// printf ("x = %d, p = %d, mt.count = %d\n", x, p, mt.count (p));
				assert (!not_prime[p] and mt[p]);
				ans.push_back (p);
				mt[x]--;
				mt[p]--;
			} else {
				int bD = bigDiv (x);
				assert (mt[bD]);
				ans.push_back (x);
				mt[bD]--;
				mt[x]--;
			}
		}
	}
	assert (len (ans) == n);
	for (int i = 0; i < n; i++)
		printf ("%d%c", ans[i], " \n"[i==n-1]);

	return 0;
}
