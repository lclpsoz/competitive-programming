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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const ll MOD = 1;
ll mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+10;
const int LOGN = 20;

int n, r;
int size[N], link[N];
priority_queue<pair<int, pii>> pq;
vector<pii> adj[N];
map<int, int> mp[N];

int find (int v) {
  return (v == link[v] ? v : find (link[v]));
}

bool same (int v, int u) {
  return find (v) == find (u);
}

void unite (int v, int u) {
  u = find (u);
  v = find (v);
  if (size[v] < size[u])
    swap (v, u);
  link[u] = v;
  size[v] += size[u];
}

// LCA
pii anc[LOGN][N];
int prof[N];

void dfs (int v, int p, int x, int w) {
  if (prof[v])
    return;
  anc[0][v] = {p, w};
  //printf ("%d %d %d\n", v, p, w);
  prof[v] = ++x;
  for (auto pp : adj[v])
    dfs (pp.x, v, x, pp.y);
}

void init () {
  
  for (int j = 1; j < LOGN; j++) {
    for (int i = 1; i <= n; i++) {
      anc[j][i].x = anc[j-1][anc[j-1][i].x].x;
      anc[j][i].y = max (anc[j-1][i].y, anc[j-1][anc[j-1][i].x].y);
    }
  }

  /*
  for (int j = 0; j < 4; j++) {
    for (int i = 1; i <= n; i++)
      printf ("%d [%d] ", anc[j][i].x, anc[j][i].y);
    putchar ('\n');
  }
  */
}

int maxi (int a, int b) {
  if (prof[a] > prof[b]) swap (a, b);

  int ret = 0;
  for (int i = LOGN-1; i >= 0; i--)
    if (prof[anc[i][b].x] >= prof[a]) {
      ret = max (ret, anc[i][b].y);
      b = anc[i][b].x;
    }

  for (int i = LOGN-1; i >= 0; i--)
    if (anc[i][a].x != anc[i][b].x) {
      ret = max (ret, max (anc[i][a].y, anc[i][b].y));
      a = anc[i][a].x;
      b = anc[i][b].x;
    }
  if (a != b)
    ret = max (ret, max (anc[0][a].y, anc[0][b].y));

  return ret;
}


int main () {
  scanf ("%d %d", &n, &r);
  for (int i = 1; i <= n; i++) {
    size[i] = 1;
    link[i] = i;
  }
  for (int i = 1; i <= r; i++) {
    int u, v, w;
    scanf ("%d %d %d", &v, &u, &w);
    mp[v][u] = w;
    pq.push ({-w, {v, u}}); 
  }

  int ans = 0;
  while (!pq.empty()) {
    int w = -pq.top().x;
    int v = pq.top().y.x;
    int u = pq.top().y.y;
    pq.pop();
    if (!same (v, u)) {
      //printf ("%d %d [%d]\n", v, u, w);
      adj[v].push_back ({u, w});
      adj[u].push_back ({v, w});
      unite (v, u);
      ans += w;
    }
  }

  //printf ("%d\n", ans);
  dfs (1, 1, 0, 0);
  init ();
  int q;
  scanf ("%d", &q);
  while (q--) {
    int u, v;
    scanf ("%d %d", &u, &v);
    int mx = maxi (u, v);
    //printf ("%d %d %d\n", ans, mx, mp[u][v]);
    printf ("%d\n", ans - mx + mp[u][v]);
  }
  
  return 0;
}
