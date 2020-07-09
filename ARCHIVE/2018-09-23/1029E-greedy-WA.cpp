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

const int N = 2e5+10;

int n;
int ans;
bool vis[N];
vector<int> adj[N];

int dfs (int v, int p) {
  if (vis[v])
    return 0;
  vis[v] = true;
  
  int d = 0;
  for (int u : adj[v])
    d = max (d, dfs (u, p+1));

  //printf ("%d %d %d ", v, d, p);
  if (d > 2) {
    //printf ("*\n");
    ++ans;
    return 1;
  }
  //putchar ('\n');

  if (d == 0)
    return p;
  return min (d+1, p);
}

int main () {
  int u, v;
  scanf ("%d", &n);
  for (int i = 0; i < n-1; i++) {
    scanf ("%d %d", &u, &v);
    adj[u].push_back (v);
    adj[v].push_back (u);
  }

  dfs (1, 0);
  printf ("%d\n", ans);
  
  return 0;
}
