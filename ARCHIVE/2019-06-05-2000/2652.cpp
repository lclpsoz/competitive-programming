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

int comp (vector<vector<int>>& lft, vector<vector<int>>& rgt) {
	if (len (lft.back()) < len (rgt.back())) return 1;
	else if (len (lft.back()) > len (rgt.back())) return 0;
	
	for (vector<int> &u : lft) {
		for (vector<int> &v : rgt) {
// 			for (int x : u)
// 				printf ("%d ", x);
// 			putchar ('\n');
// 			for (int x : v)
// 				printf ("%d ", x);
// 			putchar ('\n');
			bool now = false;
			for (int k = 0; k < len (u); k++)
				if (u[k] != v[k])
					now = true;
			if (!now) return 2; // Some pair is equal
		}
	}
	
	vector<int> &u = lft.back();
	vector<int> &v = rgt.back();
	for (int i = 0; i < len (u); i++)
		if (u[i] < v[i]) return 1;
		else if (u[i] > v[i]) return 0;
	return 0;
}

int n, m;
// vector<int> vec[45];
vector<int> adj[45];
int subTree[45];
vector<vector<vector<int>>> vec;


bool func (int u, int v) { return subTree[u] < subTree[v]; }

int fSub (int v, int p) {
// 	printf ("%d %d\n", v, p);
	subTree[v] = 1;
	for (int u : adj[v])
		if (u != p)
			subTree[v] += fSub (u, v);
	
	return subTree[v];
}

void dfs (int v, int p) {
	sort (adj[v].begin(), adj[v].end(), func);
	for (int u : adj[v])
		if (u != p)
			dfs (u, v);
}

void fVec (int v, int p, vector<int> &now) {
	now.push_back (subTree[v]);
	for (int u : adj[v])
		if (u != p)
			fVec (u, v, now);
	now.push_back (subTree[v]);
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &m);
		for (int i = 1; i <= m; i++) adj[i].clear();
		for (int u = 2; u <= m; u++) {
			int v;
			scanf ("%d", &v);
			adj[v].push_back (u);
			adj[u].push_back (v);
		}
		vector<vector<int>> now;
		for (int i = 1; i <= m; i++) {
// 			printf ("v: %d\n", i);
			fSub (i, i);
// 			printf ("aft fSub\n");
			dfs (i, i);
			now.push_back ({});
			fVec (i, i, now.back());
		}
// 		printf ("here\n");
// 		for (int v : vec[i])
// 			printf ("%d ", v);
// 		putchar ('\n');
		bool ins = true;
		for (int i = 0; i < len (vec); i++)
			if (comp (vec[i], now) == 2) {
				ins = false;
				break;	
			}
		if (ins)
			vec.push_back (now);
	}
	printf ("%d\n", len (vec));

	return 0;
}
