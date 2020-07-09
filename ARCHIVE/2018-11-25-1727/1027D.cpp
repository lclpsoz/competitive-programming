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

const int N = 2e5+100;

int n;
char vert[N];
int cost[N], adj[N];
ll ans;

int dfs (int v) {
  if (vert[v] == 'B') {
    //cout << "NO: " << v << '\n';
    return 0;
  }
  
  if (vert[v] == 'G') {
    vert[v] = 'B';
    return cost[v];
  }
  vert[v] = 'G';
  int val = min (cost[v], dfs (adj[v]));
  if (vert[v] == 'B')
    ans += val;
  vert[v] = 'B';

  //cout << v << ' ' << val << '\n';
  return val;
}

int main () {
  scanf ("%d", &n);
  
  for (int i = 1; i <= n; i++)
    scanf ("%d", &cost[i]);
  for (int i = 1; i <= n; i++)
    scanf ("%d", &adj[i]);

  for (int i = 1; i <= n; i++) {
    if (vert[i] == '\0')
      dfs (i);
    //cout << "ans: " << i << ' ' << ans << '\n';
  }
  
  printf ("%lld\n", ans);
  
  return 0;
}
