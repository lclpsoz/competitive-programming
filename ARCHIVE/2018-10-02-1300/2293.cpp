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

int row, col;
ll x, ans;
ll arr[110];

int main () {
  scanf ("%d %d", &row, &col);
  for (int i = 0; i < row; i++) {
    ll acu = 0;
    for (int j = 0; j < col; j++) {
      scanf ("%lld", &x);
      arr[j] += x;
      acu += x;
    }
    ans = max (acu, ans);
  }
  for (int i = 0; i < col; i++)
    ans = max (arr[i], ans);
  printf ("%lld\n", ans);
  
  return 0;
}
