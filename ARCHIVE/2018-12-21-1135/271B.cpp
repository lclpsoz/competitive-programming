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

const int N = 505, P = 1e5+100;

int cost[N][N];
int not_prime[P];
vector<int> primes;

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
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int x;
			scanf ("%d", &x);
			auto it = lower_bound (primes.begin(), primes.end(), x);
			cost[i][j] = abs ((*it)-x);			
		}
		
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		int acu = 0;
		for (int j = 1; j <= m; j++)
			acu += cost[i][j];
		ans = min (acu, ans);
	}
	for (int i = 1; i <= m; i++) {
		int acu = 0;
		for (int j = 1; j <= n; j++)
			acu += cost[j][i];
		ans = min (acu, ans);
	}
	
	printf ("%d\n", ans);

	return 0;
}
