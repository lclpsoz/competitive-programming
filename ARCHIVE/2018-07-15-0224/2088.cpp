#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

typedef pair<int, pii> piii;

const int MAXP = 1<<16;

int n;
int x, y;
priority_queue<pii, vector<pii>, greater<pii>> pq[18];
vector<piii> coords;
vector<pair<double, int>> adj[17];
double dp[17][MAXP];

double operator- (const pii &a, const pii &b) {
  pair<double, double> p = {a.x-b.x, a.y-b.y};
  return sqrt((p.x*p.x)+(p.y*p.y));
}

double func (int v, int perc){
  //  printf ("%d %d %lf\n", v, perc, dp[v][perc]);
  double &r = dp[v][perc];
  //  printf ("%.2lf %d\n", r, cmp (r, -1));
  if (r > 0) return r;
  r = INF;
  bool aux = false;
  for (pair<double, int> p : adj[v]) {
    int u = p.y;
    if (!(perc & 1 << (u-1))) {
      r = min (func (u, perc | 1 << (u-1))+(p.x), r);
      aux = true;
    }
  }
    
  if (!aux)
    r = (adj[v][0].x);
  //printf ("||%d: %0.2lf\n", v, r);
  return r;
}

int main ()
{
  while (scanf ("%d", &n), n) {
    for (int i = 0; i < 17; i++)
      for (int j = 0; j < MAXP; j++)
	dp[i][j] = -100.0;
    coords.clear();
    for (int i = 1; i <= n+1; i++) adj[i].clear();
    ++n;
    scanf ("%d %d", &x, &y);
    coords.pb ({1, {x, y}});
    for (int i = 2; i <= n; i++) {
      scanf ("%d %d", &x, &y);
      coords.pb ({i, {x, y}});
    }
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) {
	double w = coords[i].y-coords[j].y;
	//	printf ("  %d %d: %.2lf\n", i+1, j+1, w);
	adj[i+1].pb ({w, j+1});
	adj[j+1].pb ({w, i+1});
      }
    printf ("%.2lf\n", func (1, 1));
  }

  return 0;
}
