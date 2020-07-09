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

int n, m;
int a, b;

int main () {
  scanf ("%d %d", &n, &m);
  ll total = 0;
  ll mini = 0;
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    scanf ("%d %d", &a, &b);
    total += a;
    mini += b;
    vec.push_back (a-b);
  }
  sort (vec.begin(), vec.end());

  if (mini > m)
    printf ("-1\n");
  else {
    int ans = 0;
    while (total > m) {
      total -= vec.back();
      vec.pop_back();
      ++ans;
    }
    printf ("%d\n", ans);
  }
  
  return 0;
}
