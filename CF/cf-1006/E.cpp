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

int n, q;
vector<int> adj[N];
vector<int> vec;
bool vis[N];
int pos[N];
int sz[N];

int dfs (int u) {
  if (vis[u])
    return 0;
  vis[u] = true;
  pos[u] = len (vec);
  vec.push_back (u);

  int r = 1;
  for (int v : adj[u])
    r += dfs (v);

  sz[u] = r;
  return r;
}

int x;

int main () {
  scanf ("%d %d", &n, &q);
  for (int i = 2; i <= n; i++) {
    scanf ("%d", &x);
    adj[x].push_back (i);
    adj[i].push_back (x);
  }
  for (int i = 0; i < n; i++)
    sort (adj[i].begin(), adj[i].end());
  dfs (1);
  //for (int i = 1; i <= 9; i++)
  //  printf ("%d: %d\n", i, sz[i]);
  //for (int z : vec)
  //  printf ("%d ", z);
  
  int u, k;
  while (q--) {
    scanf ("%d %d", &u, &k);
    //printf ("%d\n", u);
    if (k > sz[u])
      printf ("-1\n");
    else
      printf ("%d\n", vec[pos[u]+k-1]);
  }
  
  
  return 0;
}
