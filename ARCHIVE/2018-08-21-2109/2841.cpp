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

int val[N];
int x;
vector<int> adj[N];
int dp[N][2];

int func (int v, bool ok) {
  if (dp[v][ok] != -1)
    return dp[v][ok];
  int yes, no;
  yes = ok ? val[v] : 0;
  no = 0;
  for (int u : adj[v]) {
    yes += func (u, false);
    no += func (u, true);
  }
  return dp[v][ok] = max (yes, no);
}

int main ()
{
  memset (dp, -1, sizeof (dp));
  int n;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", &val[i]);
  for (int i = 1; i < n; i++) {
    scanf ("%d", &x);
    adj[x-1].pb (i);
  }

  printf ("%d\n", max (func (0, 0), func (0, 1)));
  //for (int i = 0; i < n; i++)
  //printf ("%d %d\n", dp[i][0], dp[i][1]);
  

  return 0;
}
