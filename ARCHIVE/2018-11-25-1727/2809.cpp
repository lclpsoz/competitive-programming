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

using pp = pair<int, pii>;
const int K = 105, N = 1e4+10;

int n, m, q;
int st, en, total;
string str;

map<int, unordered_set<int>> used;
vector<int> path;

vector<pp> adj[N];
int dist[K][N];
priority_queue<pp, vector<pp>, greater<pp>> pq;

int ans[K];

int main () {
  ios::sync_with_stdio (false);
  cin.tie(0);
  cin >> n >> m >> q;
  cin >> st >> en;
  cin >> ws;
  getline (cin, str);
  
  // Get path
  istringstream vals (str);
  int val;
  while (vals >> val)
    path.push_back (val);
  for (int i = 0; i < len (path)-1; i++)
    used[path[i]].insert (path[i+1]);

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    if (used.count(u) && used[u].count(v)) {
      total += w;
      adj[u].push_back ({w, {false, v}}); // used
    } else
      adj[u].push_back ({w, {true, v}});    
  }

  // Dijkstra
  for (int i = 0; i < K ; i++) {
    ans[i] = 2e9;
    for (int j = 0; j < N; j++)
      dist[i][j] = 2e9;
  }
  pq.push ({0, {0, st}}); // {d, {k, v}}
  while (!pq.empty()) {
    int d = pq.top().x;
    int k = pq.top().y.x;
    int v = pq.top().y.y;
    //cout << d << " " << k << " " << v << '\n';
    pq.pop();
    if (k > 100)
      k = 100;
    if (dist[k][n] < d)
      continue;
    if (v == en)
      ans[k] = min (ans[k], d);
    for (pp p : adj[v]) {
      int u = p.y.y;
      int dd = d + p.x;
      int kk = k + p.y.x;
      if (dd < dist[kk][u]) {
	dist[kk][u] = dd;
	pq.push ({d + p.x, {k + p.y.x, p.y.y}});
      }
    }
  }
  for (int i = K-1; i >= 0; i--)
    for (int j = i-1; j >= 0; j--)
      ans[j] = min (ans[j], ans[i]);
  /*
  for (int i = 0; i < 20; i++)
    cout << i << ": " << ans[i] << '\n';
  */
  // Queries
  while (q--) {
    int k, d;
    cin >> k >> d;
    cout << (ans[k] <= total+d ? "SIM" : "NAO") << '\n';
  }
  
  return 0;
}
