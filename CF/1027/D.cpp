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

const int N = 2e5+10;

int n;
ll ans;
char color[N];
int cost[N], adj[N];

int dfs (int v) {
  if (color[adj[v]] == 'B')
    return 0;
  if (color[adj[v]] == 'G') {
    color[v] = 'B';
    color[adj[v]] = 'B';
    return cost[v];
  }
  color[v] = 'G';
  int val = min (cost[v], dfs (adj[v]));
  if (color[v] == 'B')
    ans += min (val, cost[v]);
  color[v] = 'B';

  //printf ("%d %d\n", v, val);
  return val;  
}

int main () {
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf ("%d", &cost[i]);
  for (int i = 1; i <= n; i++)
    scanf ("%d", &adj[i]);

  for (int i = 0; i <= n; i++)
    color[i] = 'W';

  for (int i = 1; i <= n; i++)
    if (color[i] == 'W') {
      //cout << "------| " << i << '\n';
      dfs (i);
      //cout << "ans: " << ans << '\n';
    }
  
  printf ("%lld\n", ans);

  return 0;
}
