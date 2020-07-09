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

bool mat[300][300];
int adj[][2] = {{1, 0},
				{0, 1},
				{-1, 0},
				{0, -1}};

int main () {
	int x, y;
	scanf ("%d %d", &x, &y);
	x += 150;
	y += 150;
	mat[150][150] = true;
	int a = 150, b = 150;
	int dir = 0, nxt = 1;
	int ans = 0;
	while (a != x or b != y) {
		do {
			a += adj[dir][0];
			b += adj[dir][1];
			mat[a][b] = true;
		} while (mat[a+adj[nxt][0]][b+adj[nxt][1]] and (a != x or b != y));
		dir = (dir+1)%4, nxt = (nxt+1)%4;
		if (a != x or b != y) ++ans;
	}
	printf ("%d\n", ans);
	
	return 0;
}
