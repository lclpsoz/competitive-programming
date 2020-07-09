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
const int LOGN = 20;
int n, q;
vector<int> adj[N];
int mat[LOGN][N];
int prof[N];

void dfs (int v, int p, int v_prof) {
  if (prof[v])
    return;
  
  prof[v] = ++v_prof;
  mat[0][v] = p;
  for (int u : adj[v])
    dfs (u, v, v_prof);
}

void fill_lca () {
  for (int i = 1; i < LOGN; i++)
    for (int j = 1; j <= n; j++)
      mat[i][j] = mat[i-1][mat[i-1][j]];

  /*
  for (int i = 0; i <= LOGN; i++) {
    for (int j = 1; j <= n; j++)
      printf ("%d ", mat[i][j]);
    putchar ('\n');
  }
  */
}

int dist (int a, int b) {
  if (prof[a] > prof[b])
    swap (a, b); // b has more depth or is equal to a.

  int x = a, y = b;
  // Make prof[a] == prof[b]
  for (int i = LOGN-1; i >= 0; i--)
    if (prof[mat[i][b]] >= prof[a])
      b = mat[i][b];

  //printf ("-|%d %d\n", a, b);
  // Find LCA
  for (int i = LOGN-1; i >= 0; i--)
    if (mat[i][a] != mat[i][b]) {
      a = mat[i][a];
      b = mat[i][b];
    }
  a = mat[0][a];
  //printf ("%d %d: %d || %d %d %d -> %d\n", x, y, a, prof[x], prof[y], prof[a], prof[x]+prof[y]-2*prof[a]);

  return (prof[x] + prof[y] - 2*prof[a]);
}

int main () {
  scanf ("%d %d", &n, &q);
  int a, b, x, y, x1, y1;
  for (int i = 0; i < n-1; i++) {
    scanf ("%d %d", &a, &b);
    adj[a].push_back (b);
    adj[b].push_back (a);
  }

  dfs (1, 1, 0);
  fill_lca();

  vector<pii> vec;
  while (q--) {
    scanf ("%d %d", &x, &y);
    vec.push_back ({x, y});
    scanf ("%d %d", &x1, &y1);
    vec.push_back ({x1, y1});

    int total = dist (x, y) + dist (x1, y1);
    a = dist (x, x1) + dist (y, y1);
    b = dist (x, y1) + dist (y, x1);
    total -= min (a, b);
    if (total >= 0)
      printf ("%d\n", (total/2)+1);
    else
      printf ("0\n");
  }
  //for (auto p : vec)
  //printf ("%d %d: %d\n", p.x, p.y, dist (p.x, p.y));
  
  return 0;
}
