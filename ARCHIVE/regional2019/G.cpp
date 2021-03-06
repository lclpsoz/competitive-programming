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

// !!!!!!!!!!!!!WA!!!!!!!!!!!!!
// !!!GREEDY ON FLOW PROBLEM!!!
// !!!!!!!!!!!!!WA!!!!!!!!!!!!!

int n;
int now[110];
int a[110][110];

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		now[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf ("%d", &a[i][j]);
	
	for (int k = 1; k <= n*n; k++)
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= n; i++)
			if (i != j and a[now[j]][j]*a[now[i]][i] < a[now[i]][j]*a[now[j]][i])
				swap (now[j], now[i]);

	for (int i = 1; i <= n; i++)
		printf ("%d%c", now[i], " \n"[i==n]);

	return 0;
}
