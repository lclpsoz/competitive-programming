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

const int N = 2e6;

bool arr[N];
bool not_prime[N];

int main () {
// 	not_prime[1] = true;
	for (int i = 2; i*i < N; i++)
		if (!not_prime[i])
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = true;
// 	for (int i = 1; i <= 20; i++)
// 		printf ("%d: %d\n", i, not_prime[i]);
	int t, n;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 1; i < N; i++)
			arr[i] = false;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf ("%d", &x);
			if (x < N)
				arr[x] = true;
		}
		if (!arr[1])
			printf ("0\n");
		else {
			int ans = 1;
			while (arr[ans+1] or not_prime[ans+1])
				++ans;
			
			printf ("%d\n", ans);
		}
	}

	return 0;
}
