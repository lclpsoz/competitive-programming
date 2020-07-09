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

const int N = 1e3 + 10;

int n, h;
int a[N];

bool check (int k) {
	vector<int> vec;
	for (int i = 1; i <= k; i++)
		vec.push_back (a[i]);
	sort (vec.begin(), vec.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < len (vec); i+=2)
		sum += vec[i];
	return sum <= h;
}

int main () {
	scanf ("%d %d", &n, &h);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	
	for (int i = 1; i <= n; i++) {
		if (!check (i)) {
			printf ("%d\n", i-1);
			exit (0);
		}
	}
	printf ("%d\n", n);

	return 0;
}
