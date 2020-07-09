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

int n, t;
map<int, int> mp;

int mdc (int a, int b) {
  if (a == 0) return b;
  return mdc (b%a, a);
}

int mmc (int a, int b) { return (a*b)/mdc (a, b); }

bool comp (pii a, pii b) {
  int mc = mmc (a.y, b.y);
  a.x *= (mc/a.y);
  b.x *= (mc/b.y);
  return a.x > b.x;
}

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);
    while (n--) {
      int x;
      scanf ("%d", &x);
      mp[x]++;
    }

    int a, b;
    pii best = {1e4+10, 1};
    a = b = -1;
    int pre = -1;
    for (pii p : mp) {
      if (p.y >= 4) {
	a = b = -1;
	printf ("%d %d %d %d\n", p.x, p.x, p.x, p.x);
	break;
      }
      if (pre != -1 && p.y >= 2) {
	//cout << p.x << ' ' << pre << '\n';
	pii now = {p.x, pre};
	if (comp (best, now)) {
	  best = now;
	  a = p.x;
	  b = pre;
	}
      }
      
      if (p.y >= 2)
	pre = p.x;
    }
    //cout << a << ' ' << b << '\n';
    if (a != -1)
      printf ("%d %d %d %d\n", a, a, b, b);

    mp.clear();
  }

  return 0;
}
