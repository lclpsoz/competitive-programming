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

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int t;

int func (int h, int m) {
  int h2, m2;
  scanf ("%d:%d", &h2, &m2);
  h2 -= h;
  m2 -= m;
  m2 += h2*60;
  if (abs(m2) <= 5)
    return 0;
  return m2;
}

int main () {
  scanf ("%d", &t);
  while (t--) {
    int n;
    scanf ("%d", &n);
    int acu = 0;
    while (n--) {
      acu += -func (8, 0);
      //printf (" %d\n", acu);
      acu += func (12, 0);
      //printf (" %d\n", acu);
      char arr[10];
      scanf ("%s", arr);
      acu += -func (14, 0);
      //printf (" %d\n", acu);
      acu += func (18, 0);
      //printf ("%d\n", acu);
    }
    if (acu < 0)
      printf ("-");
    else
      printf ("+");
    acu = abs (acu);
    int h = acu/60;
    acu %= 60;
    printf (" %02d:%02d\n", h, acu);
  }
  
  return 0;
}
