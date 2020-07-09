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

int main () {
  int n;
  cin >> n;

  ll p = 5;
  while (n > 0) {
    n -= p;
    p *= 2;
  }
  p /= 2;
  n += p;
  //cout << n << ' ' << p << '\n';
  if (p/5 > 1)
    n = (n-1)/(p/5)+1;
  string s;
  if (n == 1)
    s = "Sheldon";
  else if (n == 2)
    s = "Leonard";
  else if (n == 3)
    s = "Penny";
  else if (n == 4)
    s = "Rajesh";
  else
    s = "Howard";

  cout << s << '\n';

  return 0;
}
