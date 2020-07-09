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

vector<int> adj[N];
vector<int> topSort;
int vert[N];

bool dfs(int v) {
	if(vert[v] == 2) return true;
	if(vert[v] == 1) return false; // Tem loop
	vert[v] = 1;
	for (int u : adj[v])
		if (dfs(u) == false)
			return false;
	topSort.push_back(v);
	vert[v] = 2;
	return true;
}

bool topSortCall() {
	for(int i = 1; i <= n; i++)
		if(vert[i] == 0 and dfs(i) == false)
			return false; // Tem loop
	reverse(topSort.begin(), topSort.end());
	return true;
}

int main () {

	return 0;
}
