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
const int N = 1e3+10;

int t;
int n, k;
vector<pii> vec;
priority_queue<pp, vector<pp>, greater<pp>> pq;
int size[N], link[N];

int mdc (int a, int b) {
  if (b == 0) return a;
  return mdc (b, a%b);
}

int find (int x) {
  return (x == link[x] ? x : x = find (link[x]));
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

int weight (int x, int y) {
  pii a = vec[x], b = vec[y];
  return (mdc (abs (a.x-b.x), abs (a.y-b.y))-1);
}

int main () {
  int x, y;
  scanf ("%d", &t);
  while (t--) {
    vec.clear();
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      link[i] = i;
      size[i] = 1;
    }
    for (int i = 0; i < n; i++) {
      scanf ("%d %d", &x, &y);
      vec.push_back ({x, y});
    }
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
	pq.push ({weight (i, j), {i, j}});
    int ans = 0;
    while (!pq.empty()) {
      if (!same (pq.top().y.x, pq.top().y.y)) {
	ans += pq.top().x;
	unite (pq.top().y.x, pq.top().y.y);
      }
      pq.pop();
    }

    printf ("%d\n", ans*k);
  }
  
  return 0;
}
