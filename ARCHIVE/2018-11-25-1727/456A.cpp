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

int n;
vector<pii> vec;

int main () {
  scanf ("%d", &n);
  while (n--) {
    int p, q;
    scanf ("%d %d", &p, &q);
    vec.push_back ({p, q});
  }
  sort (vec.begin(), vec.end());
  int mx = 0;
  for (pii p : vec) {
    if (mx > p.y) {
      printf ("Happy Alex\n");
      return 0;
    }
    mx = p.y;
  }
  printf ("Poor Alex\n");

  return 0;
}
