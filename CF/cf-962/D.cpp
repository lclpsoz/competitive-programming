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

const int N = 150100;

map<ll, int> mp;
ll a[N];

int main () {
  int n;
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf ("%lld", &a[i]);
    while (mp[a[i]] != 0) {
      a[mp[a[i]]] = -1;
      mp[a[i]] = 0;
      a[i] *= 2;
    }
    mp[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += a[i] != -1;

  printf ("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1) {
      printf ("%lld", a[i]);
      if (ans)
	putchar (' ');
      --ans;
    }
  }

  return 0;
}
