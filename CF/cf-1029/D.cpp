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

int n, k;
int x;
map<int, int> mp[20];
vector<int> vec;

int main () {
  scanf ("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf ("%d", &x);
    vec.push_back (x);
    ++mp[((int)log10(x))][x%k];
    //printf ("|%d %d\n", (int)log10(x), x%k);
  }
  ll ans = 0;
  for (int y : vec) {
    llu z = y;
    --mp[((int)log10(y))][y%k];
    for (int i = 0; i <= 9; i++) {
      z *= 10;
      //printf ("%lld\n", z);
      int aux = (k-(int)(z%k))%k;
      //printf ("%d\n", aux);
      if (mp[i].count (aux))
	ans += mp[i][aux];
    }
    //printf ("%d %lld\n", y, ans);
    ++mp[((int)log10(y))][y%k];
  }

  printf ("%lld\n", ans);
  
  return 0;
}
