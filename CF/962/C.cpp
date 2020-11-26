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

const int N = 2e9;

int main () {
  string str;

  int n;
  int ans = -1;
  scanf ("%d", &n);
  string nStr = to_string (n);
  int mx = len (nStr);
  
  for (int i = 1; i*i*1LL <= N; i++) {
    int now = i*i;
    str = to_string (now);
    int k = 0;
    for (int j = 0; j < len (nStr); j++) {
      if (nStr[j] == str[k])
	++k;
      if (k == len (str)) {
	ans = mx - len (str);
	break;
      }
    }
  }

  printf ("%d\n", ans);

  return 0;
}
