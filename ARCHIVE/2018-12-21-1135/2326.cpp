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

const int N = 32;

int n, money;
int vals[N], group[N];
bool vert[N];
int st[110][110];
vector<pii> stVec;
vector<int> adj[N];

void dfs (int v) {
	if (vert[v]) return;
	vert[v] = true;
	if (group[v]) {
		int nVec = len (stVec);
		for (int i = 0; i < nVec; i++) {
			pii p = stVec[i];
			while (true) {
				p.x += vals[v];
				if ((p.x+p.y) > money)
					break;
				if (!st[p.x][p.y]) {
					st[p.x][p.y] = true;
					stVec.push_back (p);
				}
			}
		}
	} else {
		int nVec = len (stVec);
		for (int i = 0; i < nVec; i++) {
			pii p = stVec[i];
			while (true) {
				p.y += vals[v];
				if ((p.x+p.y) > money)
					break;
				if (!st[p.x][p.y]) {
					st[p.x][p.y] = true;
					stVec.push_back (p);
				}
			}
		}
	}
	for (int u : adj[v])
		dfs (u);
}

int main () {
	scanf ("%d", &n);
	scanf ("%d", &money);
	for (int i = 0; i < n; i++) {
		int v;
		char c;
		scanf ("%d", &v);
		scanf ("%d", &vals[v]);
		scanf (" %c" , &c);
		group[v] = (c == 'A');
		int qnt;
		scanf ("%d", &qnt);
		while (qnt--) {
			int u;
			scanf ("%d", &u);
			adj[v].push_back (u);
		}
	}
	
	st[0][0] = true;
	stVec.push_back ({0, 0});
	dfs (0);
	
	int ans = 101;
	for (pii p : stVec) {
		if (p.x == p.y and p.x == 0) continue;
		ans = min (ans, abs (p.x-p.y));
	}
	
	printf ("%d\n", ans);

	return 0;
}
