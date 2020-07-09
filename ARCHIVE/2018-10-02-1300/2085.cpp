#include <bits/stdc++.h>
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

using pll = pair<ll, int>;
const int N = 3e4+10;

int n, s;
vector<int> adj[N], topo;
bool vis[N];
ll vals[N];
ll dist[N];
priority_queue<pll> pq;

void dfs (int v) {
  if (vis[v])
    return;
  vis[v] = true;
  for (int u : adj[v])
    dfs (u);
  topo.push_back (v);
}

int main () {
  scanf ("%d %d", &n, &s);
  while (s--) {
    int u, v;
    scanf ("%d %d", &u, &v);
    adj[u].push_back (v);
  }
  dfs (1);
  vals[n] = 1;
  for (int v : topo) {
    if (v == n)
      continue;
    for (int u : adj[v])
      vals[v] += vals[u];
  }

  
  memset (vis, false, sizeof vis);
  // Dijkstra
  dist[1] = vals[1];
  pq.push ({dist[1], -1});
  while (!pq.empty()) {
    int v = -pq.top().y;
    ll w = pq.top().x;
    pq.pop();
    if (vis[v])
      continue;
    vis[v] = true;
    for (int u : adj[v])
      if (dist[u] < dist[v]+vals[u]) {
	dist[u] = dist[v]+vals[u];
	pq.push ({dist[u], -u});
      }
  }

  printf ("%lld\n", dist[n]);
    
  return 0;
}
