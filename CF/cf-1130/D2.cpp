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

const int N = 5010;

int n, m;
int verts[N], qnt[N];
int dist[N];
multiset<int> train;

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d %d", &a, &b);
		int d = b-a;
		if (d < 0) d += n;
		if (!verts[a]) verts[a] = d;
		else verts[a] = min (verts[a], d);
		qnt[a]++;
	}
	for (int i = 1; i <= n; i++) {
		if (qnt[i])
			dist[i] = n*(qnt[i] - 1) + verts[i];
		// printf ("%d: %d\n", i, dist[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			int d = j-i;
			if (d < 0) d += n;
			if (dist[j])
				ans = max (ans, dist[j] + d);
		}
		printf ("%d ", ans);
	}
	putchar ('\n');


	return 0;
}