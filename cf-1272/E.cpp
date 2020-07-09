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

const int INF = 1e9;
const int N = 2e5 + 10;

int n, a[N];
int ans[N];
bool vis[N];
vector<int> adj[N];

void bfs(queue<pii> q, int target) {
	memset(vis, 0, sizeof vis);
	while(!q.empty()) {
		int now = q.front().x;
		int prof = q.front().y;
		// printf("%d %d %d\n", now, a[now]%2, prof);
		q.pop();
		if(vis[now]) continue;
		vis[now] = true;
		if(a[now]%2 == target) {
			// printf("here!\n");
			ans[now] = prof;
		}
		// printf("l : %d\n", len(adj[now]));
		for(int v : adj[now]) {	
			// printf("adj : %d %d\n", now, v);
			q.push({v, prof+1});
		}
	}
}

int main () {
	scanf("%d", &n);
	memset(ans, -1, sizeof ans);
	queue<pii> odd, even;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i]%2)
			odd.push({i, 0});
		else
			even.push({i, 0});
		// printf("%d %d\n", i, a[i]);
		if(i + a[i] <= n)
			adj[i + a[i]].push_back(i);
		if(i - a[i] > 0)
			adj[i - a[i]].push_back(i);
	}
	bfs(odd, 0);
	bfs(even, 1);
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	putchar('\n');

	return 0;
}
