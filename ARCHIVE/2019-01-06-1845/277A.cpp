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

const int N = 105;

int n, m;
vector<int> lang[N];
int size[N], link[N];

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
		size[i] = 1;
		link[i] = i;
	}
	bool state = false;
	for (int i = 1; i <= n; i++) {
		int q;
		scanf ("%d", &q);
		if (q) state = true;
		while (q--) {
			int x;
			scanf ("%d", &x);
			for (int u : lang[x])
				if (!same (u, i))
					unite (i, u);
			lang[x].push_back (i);
		}
	}
	
	int ans  = 0;
	for (int i = 1; i <= n; i++)
		ans += link[i] == i;
	if (ans == 1)
		printf ("0\n");
	else {
		if (state)
			--ans;
		printf ("%d\n", ans);
	}
	
	return 0;
}
