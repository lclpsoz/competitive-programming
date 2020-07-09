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

int n, m;
int cat[N];
bool vis[N];
vector<int> adj[N];

int dfs (int v, int acu) {
  vis[v] = true;
  bool leaf = true;
  if (cat[v])
    ++acu;
  else
    acu = 0;
  if (acu > m)
    return 0;
  int r = 0;
  for (int u : adj[v])
    if (!vis[u]) {
      leaf = false;
      r += dfs (u, acu);
    }

  if (leaf)
    return r + (acu <= m);
  else
    return r;
}

int main ()
{
  scanf ("%d %d", &n, &m);
  int v, u;
  for (int i = 1; i <= n; i++)
    scanf ("%d", &cat[i]);
  for (int i = 1; i < n; i++) {
    scanf ("%d %d", &v, &u);
    adj[v].pb (u);
    adj[u].pb (v);
  }
  printf ("%d\n", dfs (1, 0));

  return 0;
}
