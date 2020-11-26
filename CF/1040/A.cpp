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

int n, a, b, x;
vector<int> vec;

int main () {
  scanf ("%d %d %d", &n, &a, &b);
  while (n--) {
    scanf ("%d", &x);
    vec.push_back (x);
  }
  n = len (vec);
  int ans = 0;
  for (int i = 0; i < n/2; i++) {
    if (vec[i] < vec[n-i-1])
      swap (vec[i], vec[n-i-1]);
    //printf ("%d %d\n", vec[i], vec[n-i-1]);
    if (vec[i] == vec[n-i-1] && vec[i] == 2) {
      ans += min (a, b)*2;
      if (n&1 && i == n/2)
	ans -= min (a, b);
    }
    else if (vec[i] != vec[n-i-1] && vec[i] == 2) {
      if (vec[n-i-1] == 0)
	ans += a;
      else
	ans += b;
    } else if (vec[i] != vec[n-i-1]) {
      printf ("-1\n");
      return 0;
    }
  }
  if (n&1) {
    if (vec[n/2] == 2)
      ans += min (a, b);
  }
  printf ("%d\n", ans);
  
  return 0;
}
