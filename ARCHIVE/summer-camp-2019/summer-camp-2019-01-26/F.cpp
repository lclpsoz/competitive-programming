#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m) % m);
}



// ------------------------------------------------------------

const int N = 1e6+10;

int sub[N];
vector<int> adj[N];

int dfs (int v, int p) {
	int ret = 1;
	for (int u : adj[v])
		if (u != p)
			ret += dfs (u, v);
	sub[ret]++;
	return ret;
}

int main () {
	int n;
	while (scanf ("%d", &n) != EOF) {
		for (auto &v : adj)
			v.clear();
		for (int i = 0; i < n-1; i++) {
			int x, y;
			scanf ("%d %d", &x, &y);
			adj[x].push_back (y);
			adj[y].push_back (x);
		}
		dfs (1, 1);
		vector<int> ans;
// 		for (int i = 1; i <= n; i++)
// 			printf ("sub(%d): %d\n", i, sub[i]);
		for (int i = n-1; i >= 1; i--)
			if (n%i == 0) {
// 				printf ("i: d%d\n", i);
				int qnt = n/i;
				for (int j = i; j <= n; j+=i)
					qnt -= sub[j];
				if (qnt <= 0)
					ans.push_back ((n/i)-1);
			}
		for (int i = 0; i < len (ans); i++)
			printf ("%d%c", ans[i], " \n"[i==len(ans)-1]);
		for (int i = 1; i <= n; i++)
			sub[i] = 0;
	}
    
    return 0;
}
