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

using pp = pair<pii, pair<int, vector<int>>>;

const int N = 1<<17;

int t;
int n, k;
pp a[N];
queue<pp> q;

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < 1<<n; i++) {
      pp p;
      scanf ("%d", &p.x.x);
      p.x.y = p.x.x;
      p.y.x = i+1;
      q.push (p);
    }
    while (len (q) > 1) {
      pp p1 = q.front();
      q.pop();
      pp p2 = q.front();
      q.pop();
      if (p2.x.x > p1.x.x)
	swap (p1, p2);
      p1.x.x = min (p1.x.y, p1.x.x-p2.x.x+k);
      p1.y.y.push_back (p2.y.x);

      q.push (p1);
    }
    pp p = q.front();
    q.pop();
    printf ("%d\n", p.y.x);
    for (int i = 0; i < len (p.y.y); i++) {
      if (i)
	putchar (' ');
      printf ("%d", p.y.y[i]);
    }
    putchar ('\n');
  }		  

  return 0;
}
