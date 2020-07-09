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

int ad, at, bd, bt;
int h;

int func (int t) {
  return h - (ad*(1 + (t/at)) + bd*(1 + (t/bt)));
}

int main () {
  int t;

  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d %d %d", &ad, &at, &bd, &bt);
    scanf ("%d", &h);
    int l = 0;
    while (func (l) > 0) ++l;
    //printf ("%d %d\n", l, r);
    if (l%at == 0 && l%bt != 0)
      printf ("Andre\n");
    else if (l%bt == 0 && l%at != 0)
      printf ("Beto\n");
    else {
      --l;
      if (l > -1)
	h -= bd * (1 + (l/bt)) + ad * (1 + (l/at));
      h -= ad;
      if (h <= 0)
	printf ("Andre\n");
      else
	printf ("Beto\n");
    }
  }
  
  return 0;
}
