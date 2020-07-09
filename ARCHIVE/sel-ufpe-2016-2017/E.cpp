#include<bits/stdc++.h>
using namespace std;

// ----------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

// ------------

const int N = 52;

int n, m;
ld base[N], delta[N], ans[N];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf ("%Lf", &base[i]);
	for (int i = 0; i < n; i++) {
		scanf ("%Lf", &delta[i]);
	}
	
	ld cur = 1.0;
	
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++)
		{
			ld aa = (1 - base[i]) * cur;
			ans[i] += aa;
			cur -= aa;
			
			base[i] *= (1 - delta[i]);
		}
	}
	
	printf("%Lf", ans[0]);
	for(int i = 1; i < n; i++)
		printf(" %Lf", ans[i]);
	putchar('\n');
	
	return 0;
}
