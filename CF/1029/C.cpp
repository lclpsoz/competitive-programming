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

int n;
vector<pair<int,pii>> vec1, vec2;

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf ("%d %d", &x, &y);
    vec1.push_back({1, {-x, y}});
    vec2.push_back({1, {y, -x}});
  }
  sort (vec1.begin(), vec1.end());
  sort (vec2.begin(), vec2.end());
  int ans = 0;
  int l = -1, r = 2e9;
  for (int i = 1; i < n; i++) {
    l = max (l, -vec1[i].y.x);
    r = min (r, vec1[i].y.y);
  }
  ans = max (ans, r-l);
  l = -1, r = 2e9;
  //for (auto p : vec2)
  //printf ("%d %d\n", p.x, p.y);
  for (int i = 1; i < n; i++) {
    //printf ("%d %d\n", -vec2[i].y, vec2[i].x);
    l = max (l, -vec2[i].y.y);
    r = min (r, vec2[i].y.x);
  }
  ans = max (ans, r-l);
  printf ("%d\n", ans);
  
  return 0;
}
