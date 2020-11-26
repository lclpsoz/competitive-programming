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

const int N = 3e5 + 10;

int n;
int typ[N];
int parent[N], qntLeaf[N], qntSons[N];
vector<int> ax[N], adj[N];
deque<int> dq;
int subMax[N], subMin[N];

void compGraph (int v, int p) {
	printf( "%d %d\n", v, p);
	parent[v] = p;
	if (v != p and typ[v] == typ[p]) {
		qntLeaf[p] += qntLeaf[v];
		qntLeaf[v] = 0;
	}
	for (int u : ax[v])
		compGraph (u, p);
}

void dfsPre (int v, int p) {
	if (typ[v] == 1)
		subMax[v] += qntLeaf[v];
	else
		subMin[v] += qntLeaf[v];
	for (int u : adj[v]) {
		dfsPre (u, v);
		subMax[v] += subMax[u];
		subMin[v] += subMin[u];
	}
}

int solve (int v, int p) {
	int now;
	vector<int> vals;
	if (typ[v] == 1 and qntLeaf[v]) {
		now = dq.back();
		dq.pop_back (); qntLeaf[v]--;
		while (subMax[v]) {
			dq.pop_front();
			subMax[v]--;
		}
		while (subMin[v]) {
			dq.pop_front();
			subMin[v]--;
		}

		return now;
	} else if (typ[v] == 0 and qntLeaf[v]) {
		qntLeaf[v]--;
		while (qntLeaf[v]--)
			dq.pop_back ();
		now = dq.back();
		dq.pop_back ();
		vals.push_back (now);
	}
	sort (adj[v].begin(), adj[v].end(), [&] (int x, int y) {
		if (typ[x] == 1 and qntLeaf[x]) return true;
		if (typ[y] == 1 and qntLeaf[x]) return false;
		if (typ[x] == 1 and subMin[x] < subMin[y]) return true;
		if (typ[y] == 1 and subMin[x] > subMin[y]) return false;
		
	});

}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &typ[i]);

	parent[1] = 1;
	for (int i = 2; i <= n; i++) {
		scanf ("%d", &parent[i]);
		qntSons[parent[i]]++;
	}

	for (int i = 2; i <= n; i++) {
		if (qntSons[i] == 0)
			qntLeaf[parent[i]]++;
		else
			ax[parent[i]].push_back (i);
	}

	compGraph (1, 1);

	for (int i = 2; i <= n; i++)
		if (qntLeaf[i]) {
			adj[parent[i]].push_back (i);
			printf ("v = %d, parent = %d, qnt = %d\n", i, parent[i], qntLeaf[i]);
		}
	if (typ[1] == 1 and qntLeaf[1])
		printf ("%d\n", n);
	else {
		dfsPre (1, 1);
		for (int i = 1; i <= n; i++)
			printf ("%d: %d %d\n", i, subMin[i], subMax[i]);
		
		for (int i = 1; i <= n; i++)
			dq.push_back (i);
		solve (1, 1);
	}

	return 0;
}
