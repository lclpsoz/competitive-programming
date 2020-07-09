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

const int N = 2e5 + 10;

int n, k, elemToComp[N];
vector<int> g[N], gr[N];
vector<bool> used;
vector<int> order, component, comp[N];
char mp[N];
vector<int> topOrder, adjComp[N];
char vert[N];

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

void topSort(int v) {
	// printf("%d: %c\n", v, vert[v]);
	assert(vert[v] != 'G');
	if(vert[v] == 'B') return;
	vert[v] = 'G';
	for(int u : adjComp[v])
		topSort(u);
	vert[v] = 'B';
	topOrder.push_back(v);
}

int main () {
	scanf("%d %d", &n, &k);
	vector<int> vec;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(--x);
	}
	for(int i = 1; i < n; i++) {
		g[vec[i-1]].push_back(vec[i]);
		gr[vec[i]].push_back(vec[i-1]);
	}
	vec.clear();
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(--x);
	}
	for(int i = 1; i < n; i++) {
		g[vec[i-1]].push_back(vec[i]);
		gr[vec[i]].push_back(vec[i-1]);
	}

	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);

	used.assign (n, false);
	int idComp = 0;
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
			for(int u : component) {
				elemToComp[u] = idComp;
				comp[idComp].push_back(u);
			}
			idComp++;
			component.clear();
		}
	}

	// for(int i = 0; i < idComp; i++) {
	// 	printf("Comp %d: ", i);
	// 	for(int v : comp[i])
	// 		printf ("%d ", v);
	// 	putchar ('\n');
	// }

	if(idComp < k)
		printf("NO\n");
	else {
		printf("YES\n");
		for(int v = 0; v < n; v++) {
			for(int u : g[v]) {
				int cv = elemToComp[v];
				int cu = elemToComp[u];
				if(cv != cu)
					adjComp[cv].push_back(cu);
			}
		}
		for(int i = 0; i < idComp; i++)
			vert[i] = 'W';
		for(int i = 0; i < idComp; i++)
			if(vert[i] != 'B')
				topSort(i);
		char c = k + 'a' - 1;
		for (int i = 0; i < idComp; i++) {
			// printf("%d ", topOrder[i]);
			mp[topOrder[i]] = c;
			if(c > 'a') --c;
		}
		// putchar('\n');
		for(int i = 0; i < n; i++)
			printf("%c", mp[elemToComp[i]]);
		putchar('\n');
	}

	return 0;
}
