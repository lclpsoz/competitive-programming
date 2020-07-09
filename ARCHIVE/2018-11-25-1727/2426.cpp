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

using pp = pair<int, pii>; // {Distance, {Vertice, Time}}
const int N = 510;

int n, st, en, m;
vector<pii> adj[N]; // {Vertice, T}
queue<pp> q;
bool vis[N][5];

int main () {
  scanf ("%d %d %d %d", &n, &st, &en, &m);
  while (m--) {
    int u, v, t;
    scanf ("%d %d %d", &u, &v, &t);
    adj[u].push_back ({v, t});
  }

  q.push ({0, {st, 0}});
  vis[0][0] = true;
  while (!q.empty() && q.front().y.x != en) {
    int d = q.front().x;
    int v = q.front().y.x;
    int t = q.front().y.y;
    //printf ("[%d] %d %d %d\n", len(q), d, v, t);
    q.pop();
    ++d;
    if (t == 3)
      t = 0;
    for (pii p : adj[v]) {
      if (t == 0 && p.y == 1 && !vis[p.x][t+1]) {
	//printf ("||%d %d\n", p.x, t+1);
	vis[p.x][t+1] = true;
	q.push ({d, {p.x, t+1}});
      } else if (t && p.y == 0 && !vis[p.x][t+1]) {
	//printf ("//%d %d\n", p.x, t+1);
	vis[p.x][t+1] = true;
	q.push ({d, {p.x, t+1}});
      }
    }
  }
  if (q.empty())
    printf ("*\n");
  else
    printf ("%d\n", q.front().x);
  
  return 0;
}
