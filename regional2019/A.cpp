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
int n, m, k;
int link[N], sz[N];
vector<pair<pii, int>> vec;
vector<int> comp[N];

int find (int x) { return x == link[x] ? x : link[x] = find (link[x]); }

bool same (int x, int y) { return find (x) == find (y); }

void unite (int x, int y) {
	x = find (x), y = find (y);
	if(sz[x] > sz[y]) swap (x, y);
	sz[y] += sz[x];
	link[x] = y;
}

int dist (pii x, pii y) {
	int a = x.x-y.x;
	int b = x.y-y.y;
	return a*a + b*b;
}

bool inter (pair<pii, int> &a, pair<pii, int> &b) {
	int s = a.y+b.y;
	return dist (a.x, b.x) <= s*s;
}

bool check (int p) {
	vector<int> &now = comp[p];
	if (len (now) == 0) return true;
	bool lft, rig;
	lft = rig = false;
	for (int v : now) {
		pair<pii, int> pp = vec[v];
		int x = pp.x.x, y = pp.x.y, s = pp.y;
		if (x-s <= 0 or y+s >= n)
			lft = true;
		if (x+s >= m or y-s <= 0)
			rig = true;
	}
	return !(lft and rig);
}

int main () {
	scanf ("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		link[i] = i, sz[i] = 1;
		int x, y, s;
		scanf ("%d %d %d", &x, &y, &s);
		vec.push_back ({{x, y}, s});
	}
	for (int i = 0; i < k; i++)
		for (int j = i+1; j < k; j++)
			if (!same (i, j) and inter (vec[i], vec[j])) unite (i, j);

	for (int i = 0; i < k; i++)
		comp[find (i)].push_back (i);
	for (int i = 0; i < k; i++)
		if (!check (i)) {
			printf ("N\n");
			exit (0);
		}
	printf ("S\n");

	return 0;
}
