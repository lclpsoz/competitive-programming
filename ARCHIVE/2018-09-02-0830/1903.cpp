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

const int MOD = 1e9 + 7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+10;

int n, m;
bool vis[N];
vector<int> adj[N];

void dfs (int v) {
  if (vis[v]) return;
  vis[v] = true;
  for (int u : adj[v])
    dfs (u);
}

int main () {
  scanf ("%d %d", &n, &m);
  int v, u;
  for (int i = 0; i < m; i++) {
    scanf ("%d %d", &v, &u);
    adj[v].push_back (u);
    adj[u].push_back (v);
  }

  dfs (1);
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      printf ("Nao Bolada\n");
  printf ("Bolada\n");
  
  return 0;
}
