#include <bits/stdc++.h>
using namespace std;

// ------------
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
	return (int)(((x%m) + m)%m);
}

// ------------

const int N = 1e5 + 10;

pair<int, int> edges[N];
int par[N], rnk[N], cnt[N], comp;

int fnd(int u){
	if(par[u] == u) return u;
	return par[u] = fnd(par[u]);
}

void join(int a, int b){
	a = fnd(a), b = fnd(b);
	if(a != b){
		if(rnk[a] < rnk[b]) swap(a, b);
		else if(rnk[a] == rnk[b]) rnk[a]++;
		par[b] = a;
		comp--;
	}
}

int p[N], ans[N];

int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		par[i] = i;
	}
	comp = n;
	
	for(int i = 0; i < m; i++){
		scanf("%d %d", &edges[i].x, &edges[i].y);
	}
	
	for(int i = 0; i < m; i++){
		scanf("%d", &p[i]); p[i]--;
	}
	
	for(int i = m - 1; i >= 0; i--){
		ans[i] = comp;
		join(edges[p[i]].x, edges[p[i]].y);
	}
	
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
	
	return 0;
}