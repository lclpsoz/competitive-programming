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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9 + 7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
string s, now, bef;

int main () {
  scanf ("%d", &n);
  int ans = 1;
  cin >> bef;
  for (int i = 1; i < n; i++) {
    cin >> now;
    if (now != bef)
      ++ans;
    bef = now;
  }

  printf ("%d\n", ans);
  
  
  return 0;
}
