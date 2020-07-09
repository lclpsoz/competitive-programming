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

const int N = 1e5+10;

int n;
vector<pii> adj[11];
vector<pair<pii, int>> vec;
bool vis[N];

int dfs (int v, int id, int d) {
  if (vis[id])
    return d-1;
  vis[id] = true;
  int mx = d;
  for (pii p : adj[v])
    mx = max (dfs (p.x, p.y, d+1), mx);

  return mx;
}

int main () {
  while (scanf ("%d", &n) != EOF) {
    for (int i = 0; i < 10; i++)
      adj[i].clear();
    vec.clear();
    for (int i = 1; i <= n; i++) {
      int x, y;
      scanf ("%d %d", &x, &y);
      adj[x].push_back ({y, i});
      adj[y].push_back ({x, i});
      vec.push_back ({{x, y}, i});
    }
    int ans = -1;
    for (auto p : vec) {
      int aux = dfs (p.x.x, p.y, 1)-1;
      vis[p.y] = false;
      ans = max (ans, aux + dfs (p.x.y, p.y, 1));
      memset (vis, false, sizeof vis);
      
      aux = dfs (p.x.y, p.y, 1)-1;
      vis[p.y] = false;
      ans = max (ans, aux + dfs (p.x.x, p.y, 1));
      memset (vis, false, sizeof vis);
      //printf ("|%d\n", ans);
    }


    printf ("%d\n", ans);
  }
  
  return 0;
}
