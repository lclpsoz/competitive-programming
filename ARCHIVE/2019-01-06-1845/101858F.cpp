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

const int N = 1e5+100;

int n, m;
pii edge[N];
vector<int> ans;
int size[N], link[N], query[N];

int find (int a) {
	if (a == link[a])
		return a;
	return link[a] = find (link[a]);
}

bool same (int a, int b) {
	return find (a) == find (b);
}

void unite (int a, int b) {
	a = find (a);
	b = find (b);
	if (size[a] > size[b]) swap (a, b);
	size[b] += size[a];
	link[a] = b;
}


int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		link[i] = i;
		size[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf ("%d %d", &u, &v);
		edge[i] = {v, u};
	}
	
	for (int i = 0; i < m; i++)
		scanf ("%d", &query[i]);

	for (int i = m-1; i >= 0; i--) {
		ans.push_back (n);
		pii p = edge[query[i]];
		if (!same (p.x, p.y)) {
			unite (p.x, p.y);
			--n;
		}
	}
	
	for (auto it = ans.rbegin(); it != ans.rend(); it++) {
		printf ("%d\n", *it);
	}
	

	return 0;
}
