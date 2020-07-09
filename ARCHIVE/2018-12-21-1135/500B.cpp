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

const int N = 310;

int n;
int arr[N];
bool adj[N][N];
bool vis[N];
vector<int> comp;

void dfs (int v) {
	if (vis[v]) return;
	comp.push_back (v);
	vis[v] = true;
	for (int u = 0; u < n; u++)
		if (adj[v][u])
			dfs (u);
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			scanf (" %c", &c);
			adj[i][j] = c == '1';
		}
	
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		
		dfs (i);
		vector<int> vals;
		for (int &x : comp)
			vals.push_back (arr[x]);
		sort (vals.begin(), vals.end());
		sort (comp.begin(), comp.end());
		for (int i = 0; i < len (vals); i++)
			arr[comp[i]] = vals[i];
		comp.clear();
	}
	
	for (int i = 0; i < n; i++) {
		if (i) putchar (' ');
		printf ("%d", arr[i]);
	}
	putchar ('\n');

	return 0;
}
