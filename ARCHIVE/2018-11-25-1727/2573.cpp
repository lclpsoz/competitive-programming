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

point luan, lari;

struct point {
  ld x, y;
};

struct rect {
  point a, d; // upper left; lower right;
  point b, c; // lower left; lower right;
};

ld operator- (point &a, point &b) {
  ld x = a.x-b.x;
  ld y = a.y-b.y;
  return (x*x + y*y);
}

ld verif (point x) {
  return ((x-luan) - (x-lari));
}

int main () {
  
  return 0;
}
