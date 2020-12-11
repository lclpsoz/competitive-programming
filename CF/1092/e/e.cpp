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

const int N = 1e3 + 10;

vector<vi> adj[N];
bitset<N> vis;

void dfs_far(int v, int p, int prof, int &v_far_prof, int &v_far) {
	if (prof > v_far_prof) {
		v_far_prof = prof;
		v_far = v;
	}
	vis[v] = 1;
	for (int u : adj[v])
		if (u != p)
			dfs_far (u, v, prof+1, v_far_prof, v_far);
}

int dfs_mid(int v, int p, int prof, int v_target, int prof_mid, int &v_mid) {
	if (v == v_target)
		return v;
	for (int u : adj[v])
		if (u != p) {
			if (dfs_mid(u, v, v_target) == v_target) {
				if (prof == prof_mid)
					v_mid = v;
				return v_target;
			}
		}
	return -1;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int v_far_prof = -1, v_st, v_en;
			dfs_far(i, i, 0, v_far_prof, v_st);
			v_far_prof = -1;
			dfs_far(v_st, v_st, 0, v_far_prof, v_en);

		}
	}


	return 0;
}
