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

const int MOD = 998'244'353;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+100;

int n, m;
string strA, strB;
int bit[N];

int sum (int p) {
	int r = 0;
	for (; p >= 1; p-=p&-p)
		r += bit[p];
	return r;
}

void add (int p, int v) {
	for (; p < N; p+=p&-p)
		bit[p] += v;
}

int powMod (int b, int p) {
	int r = 1;
	while (p) {
		if (p&1) r = mod (b*1LL*r);
		b = mod (b * 1LL * b);
		p >>= 1;
	}
	
	return r;
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> n >> m;
	cin >> strA >> strB;
	for (int i = 0; i < m; i++)
		if (strB[i] == '1') {
			add (1, 1);
			add (m-i+1, -1);
		}
		
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (strA[i] == '1') {
			int p = n-i-1;
// 			printf ("%d: %d\n", p, sum (p+1));
			ans = mod (ans + mod (sum (p+1) * 1LL * powMod (2, p)));
		}
	}
	
	printf ("%d\n", ans);

	return 0;
}
