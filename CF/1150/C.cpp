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

const int N = 4e5 + 10;

int n;
int q1, q2;
int not_prime[N];
vector<int> primes;

int main () {
	for (int i = 2; i*i < N; i++)
		if (!not_prime[i])
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = true;
	for (int i = 2; i < N; i++)
		if (!not_prime[i])
			primes.push_back (i);

	scanf ("%d", &n);
	while (n--) {
		int x;
		scanf ("%d", &x);
		if (x == 1) q1++;
		else q2++;
	}
	int ans = 0, now = 0;
	reverse (primes.begin(), primes.end());
	vector<int> vAns;
	while (q1 or q2) {
		// printf ("%d %d %d\n", now, q1, q2);
		if (primes.back() <= now) {
			ans += primes.back() == now;
			primes.pop_back ();
		} else if (q2 and q1) {
			if (primes.back()-now >= 2)
				--q2, now += 2, vAns.push_back (2);
			else
				--q1, now++, vAns.push_back (1);
		} else if (q1) --q1, now++, vAns.push_back (1);
		else --q2, now+=2, vAns.push_back (2);
	}
	if (primes.back () == now) ++ans;
	// printf ("%d\n", ans);
	for (int v : vAns)
		printf ("%d ", v);
	putchar ('\n');

	return 0;
}
