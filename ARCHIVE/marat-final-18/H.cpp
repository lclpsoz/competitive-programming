#include "bits/stdc++.h"
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

using pp = pair<pair<ll, int>, int>;

const int MAXN = 1e4+10;

int n, m;
priority_queue<pp, vector<pp>, greater<pp>> pq;
bool check[MAXN];
vector<pp> adj[MAXN];
ll ans;

int main () {
  scanf ("%d %d", &n, &m);
  while (m--) {
    int x, y, l, c;
    scanf ("%d %d %d %d", &x, &y, &l, &c);
    adj[x].push_back ({{l, c}, y});
    adj[y].push_back ({{l, c}, x});
  }

  pq.push ({{0, 0}, 1});
  while (!pq.empty()) {
    ll l = pq.top().x.x;
    int c = pq.top().x.y;
    int x = pq.top().y;
    pq.pop();
    if (check[x]) continue;
    ans += c;
    check[x] = true;
    for (auto p : adj[x])
      pq.push ({{p.x.x + l, p.x.y}, p.y});
  }
  printf ("%lld\n", ans);

  return 0;
}
