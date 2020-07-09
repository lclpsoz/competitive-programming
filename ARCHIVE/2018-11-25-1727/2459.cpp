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

const int N = 105;

int link[N], size[N];
priority_queue<pp, vector<pp>, greater<pp>> pq;

int find (int x) {
  if (x == link[x]) return x;
  return x = find (link[x]);
}

bool same (int x, int y) {
  return find (x) == find (y);
}

void unite (int x, int y) {
  x = find (x);
  y = find (y);
  if (size[x] > size[y])
    swap (x, y);
  size[y] += size[x];
  link[x] = y;
}

int main () {
  
  int n, f, r;
  int a, b, w;
  vector<pp> vec;
  scanf ("%d %d %d", &n, &f, &r);
  for (int i = 1; i <= n; i++) {
    size[i] = 1;
    link[i] = i;
  }
  for (int i = 0; i < f; i++) {
    scanf ("%d %d %d", &a, &b, &w);
    pq.push ({w, {a, b}});
  }

  int ans = 0;
  while (!pq.empty()) {
    if (!same(pq.top().y.x, pq.top().y.y)) {
      unite (pq.top().y.x, pq.top().y.y);
      ans += pq.top().x;
    }
    pq.pop();
  }
  
  for (int i = 0; i < r; i++) {
    scanf ("%d %d %d", &a, &b, &w);
    pq.push ({w, {a, b}});
  }
  while (!pq.empty()) {
    if (!same(pq.top().y.x, pq.top().y.y)) {
      unite (pq.top().y.x, pq.top().y.y);
      ans += pq.top().x;
    }
    pq.pop();
  }
  
  printf ("%d\n", ans);  
  
  return 0;
}
