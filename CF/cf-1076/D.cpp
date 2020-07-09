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

const int N = 3e5+100;
using pp = pair<ll, pii>;

int n, m, k;
priority_queue<pp, vector<pp>, greater<pp>> pq;
vector<pp> adj[N];
bool verif[N];

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf ("%d %d %d", &a, &b, &w);
		adj[a].push_back ({w, {b, i+1}});
		adj[b].push_back ({w, {a, i+1}});
	}
	
	verif[1] = true;
	for (auto p : adj[1])
		pq.push (p);
	
	vector<int> ans;
	while (k and !pq.empty()) {
		pp p = pq.top();
		pq.pop();
		if (verif[p.y.x])
			continue;
		verif[p.y.x] = true;
		ans.push_back (p.y.y);
		for (auto ax : adj[p.y.x])
			pq.push ({ax.x+p.x, ax.y});
		--k;
	}
	
	printf ("%d\n", len (ans));
	for (int i = 0; i < len (ans); i++) {
		if (i)
			putchar (' ');
		printf ("%d", ans[i]);
	}
	putchar ('\n');
	

	return 0;
}
