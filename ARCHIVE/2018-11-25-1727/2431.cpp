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

int a1, b1, a2, b2, a, b;

int main () {
  cin >> a1 >> b1 >> a2 >> b2 >> a >> b;
  if (a1 < b1)
    swap (a1, b1);
  if (a2 < b2)
    swap (a2, b2);
  if (a < b)
    swap (a, b);
  if ((a1 >= a && b1 >= b) || (a2 >= a && b2 >= b))
    printf ("S\n");
  else if ((a1 >= a && a2 >= a) && (b1+b2 >= b))
    printf ("S\n");
  else if ((a1 >= b && a2 >= b) && (b1+b2 >= a))
    printf ("S\n");
  else if ((b1 >= a && b2 >= a) && (a1+a2 >= b))
    printf ("S\n");
  else if ((b1 >= b && b2 >= b) && (a1+a2 >= a))
    printf ("S\n");
  
  else if ((a1 >= a && b2 >= a) && (b1+a2 >= b))
    printf ("S\n");
  else if ((a1 >= b && b2 >= b) && (b1+a2 >= a))
    printf ("S\n");
  else if ((b1 >= a && a2 >= a) && (a1+b2 >= b))
    printf ("S\n");
  else if ((b1 >= b && a2 >= b) && (a1+b2 >= a))
    printf ("S\n");
  else
    printf ("N\n");
  
  return 0;
}
