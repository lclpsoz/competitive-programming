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

vector<int> c;
int ans[1010], sum = 0;

int main () {
	int n, m, d;
	scanf ("%d %d %d", &n, &m, &d);
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d", &x);
		c.push_back (x);
		sum += x;
	}
	int pos = 0;
	int lst = 0;
	for (int i = 1; i <= n and pos < m; i++) {
		if (ans[i]) continue;
		if (sum + i > n or i-lst == d) {
			for (int j = i; j < i+c[pos]; j++)
				ans[j] = pos+1;
			lst = i+c[pos]-1;
			sum -= c[pos];
			++pos;
		}
	}
	int q0 = 0;
	for (int i = n; i >= 1; i--)
		if (ans[i] == 0) ++q0;
		else break;
	if (q0 >= d)
		printf ("NO\n");
	else {
		printf ("YES\n");
		for (int i = 1; i <= n; i++)
			printf ("%d ", ans[i]);
		putchar ('\n');
	}


	return 0;
}
