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

const int N = 1e5;

vector<int> primes, ans;
bool not_prime[N];

int main () {
	for (int i = 2; i*i < N; i++)
		if (!not_prime[i])
			for (int j = i*i; j < N; j+=i) not_prime[j] = true;

	for (int i = 2; i < N; i++)
		if (!not_prime[i]) primes.push_back (i);

	int n;
	scanf ("%d", &n);
	while (n--) {
		int x;
		scanf ("%d", &x);
		bool ok = true;
		if (x == 1) continue;
		for (int v : primes) {
			if (v == x) break;
			if (x%v == 0) {
				ok = false;
				break;
			}
		}
		if (ok) ans.push_back (x);
	}
	sort (ans.begin(), ans.end());
	ans.resize (unique (ans.begin(), ans.end()) - ans.begin());
	printf ("%d\n", len (ans));
	if (len (ans) == 0) putchar ('\n');
	for (int i = 0; i < len (ans); i++) {
		printf ("%d", ans[i]);
		if (i == len(ans)-1)
			printf (".\n");
		else
			printf (", ");
	}

	return 0;
}
