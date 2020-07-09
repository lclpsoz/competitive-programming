#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
#define X real()
#define Y imag()
#define mp make_pair
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int INF = 1e9;
  
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+10;

vector<int> adj[N];
bool vis[N];

int dfs (int v, int lvl) {
  //printf ("%*d [%d]\n", lvl, v, lvl);
  if (vis[v])
    return -1;
  vis[v] = true;
  int r = lvl;
  for (int u : adj[v])
    r = max (r, dfs (u, lvl+1));

  return r;
}

int main ()
{
  int n, a;
  int u, v;
  scanf ("%d %d", &n, &a);
  for (int i = 1; i < n; i++) {
    scanf ("%d %d", &u, &v);
    adj[u].pb (v);
    adj[v].pb (u);
  }
  printf ("%d\n", dfs (a, 1));

  return 0;
}
