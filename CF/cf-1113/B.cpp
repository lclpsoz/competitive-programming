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

const int N = 5e4 + 10;

vector<int> divs[110];
int a[N];

int main () {
	for (int i = 2; i <= 100; i++)
		for (int j = 2; j < i; j++)
			if (i%j == 0)
				divs[i].push_back (j);
// 	for (int i = 2; i <= 20; i++) {
// 		printf ("%d: ", i);
// 		for (int d : divs[i])
// 			printf ("%d ", d);
// 		putchar ('\n');
// 	}
	int n;
	scanf ("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		sum += a[i];
	}
	int ans = sum;
	sort (a, a+n);
	for (int i = 1; i < n; i++)
		for (int d : divs[a[i]])
			ans = min (ans, sum + (a[0]*d - a[0]) + (a[i]/d - a[i]));
	printf ("%d\n", ans);
	return 0;
}
