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

const int N = 2e5+100;

int n;
pii adjAux[N];
int adj[N];

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		adjAux[i] = {x, y};
	}
	
	if (n == 3) {
		adj[1] = 2;
		adj[2] = 3;
		adj[3] = 1;
	} else {
		for (int i = 2; i <= n; i++) {
			int x, y;
			x = adjAux[i].x;
			y = adjAux[i].y;
			
			if (adjAux[x].x != y and adjAux[x].y != y) {
				adj[i] = y;
				adj[y] = x;
			} else {
				adj[i] = x;
				adj[x] = y;
			}
		}
	}
	int v = 1;
	int q = 0;
	do {
		if (q) putchar (' ');
		q = 1;
		printf ("%d", v);
		v = adj[v];
	} while (v != 1);
	putchar ('\n');
	
	return 0;
}