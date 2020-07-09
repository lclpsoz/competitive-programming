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
pair<ld, ld> c, t;
ld r1, r2;

ld operator- (pair<ld, ld> &a, pair<ld, ld> &b) {
  ld x = a.x-b.x;
  ld y = a.y-b.y;
  return (sqrt ((x*x)+(y*y)));
}

char inside () {
  ld d = c-t;
  if (cmp (r1, d) == 1)
    return 'I';
  else if (cmp (r2, d) > -1)
    return 'B';
  return '-';
}

int main () {
  
  pii chiq, popis;
  while (scanf ("%d", &n), n) {
    chiq = popis = {0, 0};
    n *= 2;
    scanf ("%Lf %Lf %Lf %Lf", &c.x, &c.y, &r1, &r2);
    for (int i = 0; i < n; i++) {
      scanf ("%Lf %Lf", &t.x, &t.y);
      char now = inside();
      if (i&1) {
	// Popises
	if (now == 'I')
	  popis.x++;
	else if (now == 'B')
	  popis.y++;
      }
      else
	// Chiquinha
	if (now == 'I')
	  chiq.x++;
	else if (now == 'B')
	  chiq.y++;
    }

    if (popis.x > chiq.x || (popis.x == chiq.x && popis.y > chiq.y))
      printf ("P > C\n");
    else if (chiq.x > popis.x || (chiq.x == popis.x && chiq.y > popis.y))
      printf ("C > P\n");
    else
      printf ("C = P\n");
  }
  
  return 0;
}
