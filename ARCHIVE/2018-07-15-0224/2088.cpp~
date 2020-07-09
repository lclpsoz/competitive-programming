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

int n;
int x, y;
priority_queue<pii, vector<pii>, greater<pii>> pq[18];
vector<piii> coords;
bool vis[18];

int operator- (const pii &a, const pii &b) {
  pii p = {a.x-b.x, a.y-b.y};
  return (p.x*p.x)+(p.y*p.y);
}

int main ()
{
  int w;
  while (scanf ("%d", &n), n) {
    coords.clear();
    memset (vis, 0, sizeof (vis));
    ++n;
    scanf ("%d %d", &x, &y);
    coords.pb ({1, {x, y}});
    for (int i = 2; i <= n; i++) {
      scanf ("%d %d", &x, &y);
      coords.pb ({i, {x, y}});
    }
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) {
	w = coords[i].y-coords[j].y;
	printf ("%d %d: %.2lf\n", i+1, j+1, sqrt(w));
	pq[i+1].push ({w, j+1});
	pq[j+1].push ({w, i+1});
      }
    double ans = 0;
    vis[1] = true;
    int prox = pq[1].top().y;
    ans += sqrt(pq[1].top().x);
    vis[prox] = true;
    pq[1].pop();
    while (!pq[1].empty()) pq[1].pop();
    
    while (1) {
      printf ("|%d %lf\n", prox, ans);
      int now = prox;
      while (!pq[now].empty() && vis[pq[now].top().y]) pq[now].pop();
      if (pq[now].empty()) {
	ans += sqrt(coords[0].y-coords[now-1].y);
	break;
      }
      prox = pq[now].top().y;
      ans += sqrt(pq[now].top().x);
      while (!pq[now].empty()) pq[now].pop();
      vis[prox] = true;
    }
    printf ("%.2lf\n", ans);
  }

  return 0;
}
