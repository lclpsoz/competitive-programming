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

map<char, int> mp = {{'q', 9}, {'r', 5}, {'b', 3}, {'n', 3}, {'p', 1}};
char c;
int wt, bl;

int main () {
  for (int i = 0; i < 64; i++) {
    scanf (" %c", &c);
    if (c >= 'A' && c <= 'Z')
      wt += mp[tolower (c)];
    else if (c != '.')
      bl += mp[c];
  }
  printf ("%s\n", wt > bl ? "White" : (bl > wt ? "Black" : "Draw"));

  return 0;
}
