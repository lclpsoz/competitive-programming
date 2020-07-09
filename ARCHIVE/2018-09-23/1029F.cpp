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

ll a, b, c;
vector<pair<ll, ll>> vecA, vecB, sum;

int main () {
  scanf ("%lld %lld", &a, &b);
  c = a+b;
  //printf ("c: %lld\n", c);
  for (int i = (int)sqrtl(c); i >= 1; i--) {
    if (a%i == 0)
      vecA.push_back ({i, a/i});
    if (b%i == 0)
      vecB.push_back ({i, b/i});
    if (c%i == 0)
      sum.push_back ({i, c/i});
  }
  int itA, itB, itS;

  itA = 0;
  itB = 0;
  itS = 0;

  while (itS < len(sum)) {
    while (sum[itS].x < vecA[itA].x)
      itA++;
    while (sum[itS].x < vecB[itB].x)
      itB++;
    if ((sum[itS].x >= vecA[itA].x && sum[itS].y >= vecA[itA].y) ||
	(sum[itS].x >= vecB[itB].x && sum[itS].y >= vecB[itB].y))
      break;
    itS++;
  }
  if (itS == len (sum))
    itS = len (sum)-1;

  printf ("%lld\n", 2*sum[itS].x + 2*sum[itS].y);
  
  return 0;
}
