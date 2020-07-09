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

int n, x;
ll acu, ans;
vector<int> vec;

int main () {
  while (scanf ("%d", &n), n) {
    ans = acu = 0;
    vec.clear();
    while (n--) {
      scanf ("%d", &x);
      vec.push_back (x);
    }
    reverse (vec.begin(), vec.end());

    for (int y : vec) {
      ans += y + acu;
      acu += acu+y;
      //printf ("|%lld %lld\n", acu, ans);
    }

    printf ("%lld\n", ans);
  }
  
  return 0;
}
