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
vector<int> order, comp[N];
char mp[N];
vector<int> topOrder, adjComp[N];
char vert[N];
int low[N], tin[N], component[N];
int timer, idComp;
vector<int> stk;

void tarjan(int v) {
	low[v] = tin[v] = ++timer;
	stk.emplace_back(v);
	for(int u : adj[v]) {
		if(!tin[u])
			tarjan(u);
		if(component[u] == -1)
			low[v] = min(low[v], low[u]);
	}

	if(low[v] == tin[v]) {
		while(true) {
			int u = stk.back();
			stk.pop_back();
			component[u] = idComp;
			if(u == v) break;
		}
		idComp++;
	}
}

void scc() {
	memset(low, 0, sizeof low);
	memset(tin, 0, sizeof tin);
	memset(component, -1, sizeof component);
	idComp = timer = 0;
	for(int v = 0; v < n; v++)
		if(!tin[v]) tarjan(v);
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
		// gr[vec[i]].push_back(vec[i-1]);
	}
	vec.clear();
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(--x);
	}
	for(int i = 1; i < n; i++) {
		g[vec[i-1]].push_back(vec[i]);
		// gr[vec[i]].push_back(vec[i-1]);
	}
	scc();

	// for(int i = 0; i < idComp; i++) {
	// 	printf("Comp %d: ", i);
	// 	for(int v : comp[i])
	// 		printf ("%d ", v);
	// 	putchar ('\n');
	// }

	for(int i = 0; i < n; i++) {
		// printf("%d %d\n", i, component[i]);
		comp[component[i]].push_back(i);
		elemToComp[i] = component[i];
	}

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