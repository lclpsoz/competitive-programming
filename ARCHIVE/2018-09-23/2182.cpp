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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

typedef pair<pii, int> piii;
const int N = 1e5+10;

int n, m;
set<piii> s;
vector<pii> adj[N];
bool vis[N];
ld vals[N];
vector<int> vert;
int now;

void dfs (int u) {
  if (vis[u]) return;
  vis[u] = true;
  vert.push_back (u);

  for (auto p : adj[u]) {
    int v = p.x;
    int w = p.y;
    if (u > v)
      s.insert ({{v, u}, w});
    else
      s.insert ({{u, v}, w});
    dfs (v);
  } 
}

int main () {
  int u, v, w;
  scanf ("%d %d", &n, &m);
  while (m--) {
    scanf ("%d %d %d", &u, &v, &w);
    adj[u].push_back ({v, w});
    adj[v].push_back ({u, w});
  }

  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      ++now;
      dfs (i);
      w = 0;
      for (auto p : s)
	w += p.y;
      ld aux;
      if (s.empty())
	aux = 0;
      else
	aux = (ld)w/s.size();
      for (int uu : vert)
	vals[uu] = aux;
      
      vert.clear(); 
      s.clear();
    }

  ld mini = 2e9;
  int ans;
  for (int i = n; i >= 1; i--) {
    //printf ("%d: %Lf\n", i, vals[i]);
    if (cmp(vals[i], mini) == -1) {
      ans = i;
      mini = vals[i];
    }
  }
  printf ("%d\n", ans);
  
  return 0;
}
