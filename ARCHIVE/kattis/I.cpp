#include "bits/stdc++.h"
using namespace std;

// -------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int) (((x%m) + m)%m);
}

// ------
const int N = 250'010;
int n, k, m;
vi g[N];
queue<int> q;
vector<pii> routes;
int vis[N];

int main () {
	
	cin >> n >> k >> m;
	
	for(int i = 0; i < k; i++)
	{
		int u, v;
		cin >> u >> v;
		
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	
	for(int i = 0; i < m; i++)
	{
		int s, t;
		cin >> s >> t;
		
		routes.emplace_back({s, t});
		q.push(t);
	}
	
	int ans = 0;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		
		
	}
	
	cout << ans << endl;
	
	return 0;
}