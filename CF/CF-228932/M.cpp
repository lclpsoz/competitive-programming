#define _MATH_DEFINES_DEFINED
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

llu lq;
llu a, b;
string str;
long double pi = 3.14159265358979323846264338327950288419716939937510L;

bool func () {
  if (b > a)
    swap (a, b);

  a *= 1000000000;
  b *= 1000000000;
  lq *= 1000000000;
  ld l = pi/2;
  ld r = 0;
  int qnt = 0;
  while (cmp (l, r) && qnt < 1e6) {
    ld md = (l+r)/2;
    ld cmpVal = cmp (cos (md)*a + sin (md)*b, (ld) lq);
    //printf ("%Lf\n", cmpVal);
    if (cmpVal <= 0)
      l = md;
    else
      r = md+EPS;
    ++qnt;
  }

  //printf ("%Lf\n", cos(l)*a + sin(l)*b);
  //printf ("%Lf\n", sin(l)*a + cos(l)*b);
  //printf ("%.30Lf\n", l);
  return cmp (sin (l)*a + cos (l)*b, (ld) lq) <= 0;
}

int main () {
  llu r, lt;
  cin >> lq;
  cin >> str;
  //printf ("%Lf\n", cos (pi/12));
  if (str == "retangulo") {
    cin >> a >> b;
    if (a <= lq && b <= lq)
      printf ("Sim\n");
    else if (a < lq || b < lq)
      printf ("%s\n", func () ? "Sim" : "Nao");
    else
      printf ("Nao\n");
  } else if (str == "triangulo") {
    cin >> lt;
    if (cmp (cos(pi/12)*lt, lq) <= 0)
      printf ("Sim\n");
    else
      printf ("Nao\n");
  } else {
    cin >> r;
    printf ("%s\n", 2*r <= lq ? "Sim" : "Nao");
  }
  
  return 0;
}
