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

const int N = 2e5+10;

int n;
int a, b;
char str[N];
vector<int> vec;

int main () {
  scanf ("%d %d %d", &n, &a, &b);
  scanf ("%s", str);

  int acu = 0;
  int each = 0;
  int spec = 0;
  for (int i = 0; i < n; i++)
    if (str[i] == '.')
      ++acu;
    else if (acu) {
      each += acu/2;
      if (acu % 2 != 0)
	++spec;
      acu = 0;
    }
  if (acu) {
    each += acu/2;
    if (acu % 2 != 0)
      ++spec;
  }

  int ans = 0;

  ans += min (each, a);
  ans += min (each, b);

  a = max (0, a-each);
  b = max (0, b-each);

  ans += min (spec, a + b);

  printf ("%d\n", ans);

  return 0;
}
