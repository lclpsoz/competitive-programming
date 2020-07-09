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

int n;
ll total, acu;
vector<int> vec;

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf ("%d", &x);
    vec.push_back (x);
    total += x;
  }
  if (total % 2 == 1) {
    printf ("N\n");
    return 0;
  }
  
  for (int i = 0; i < n; i++)
    vec.push_back (vec[i]);

  int l = 0, r = 0;
  acu = vec[l];
  while (l <= n-1 && r <= len (vec)-1) {
    while (r < len (vec)-1 && acu < total/2) {
      ++r;
      acu += vec[r];
    }
    while (l < n-1 && acu > total/2) {
      acu -= vec[l];
      ++l;
    }
    if (acu == total/2) {
      //printf ("%d %d here\n", l, r);
      int l1, r1;
      ll acu2 = acu-vec[l];
      l1 = l+1;
      r1 = r+1;
      acu2 += vec[r1];
      while (l1 < r && r1 < len (vec)-1) {
	while (r1 < len (vec)-1 && acu2 < total/2) {
	  ++r1;
	  acu2 += vec[r1];
	}
	while (l1 < r && acu2 > total/2) {
	  acu2 -= vec[l1];
	  ++l1;
	}
	if (acu2 == total/2) {
	  //printf ("%d %d %d %d\n", l, r, l1, r1);
	  printf ("Y\n");
	  return 0;
	}
      }
    }
    acu -= vec[l];
    ++l;
  }
  printf ("N\n");

  return 0;
}
