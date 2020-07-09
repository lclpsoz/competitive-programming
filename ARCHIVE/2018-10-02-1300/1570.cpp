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

int t;
vector<ll> vec;
ll p, q;

int main () {
  for (ll i = 1; i < (1<<16); i++)
    vec.push_back (i*i);
  scanf ("%d", &t);
  int caso = 1;
  while (t--) {
    printf ("Case %d:\n", caso++);
    scanf ("%lld %lld", &p, &q);
    p += q;
    if (p <= 1)
      printf ("Impossible.\n");
    else {
      int l, r;
      l = r = 0;
      bool ans = false;
      while (l < len (vec) && vec[l] < p) {
	while (r <= l && (vec[l] + vec[r]) < p) {
	  ++r;
	  //printf ("%d %d\n", l, r);
	}
	if ((vec[l] + vec[r]) != p) {
	  r = max (0, r-2);
	  ++l;
	}
	else {
	  ans = true;
	  break;
	}
      }
      if (!ans)
	printf ("Impossible.\n");
      else
	printf ("%d %d\n", l+1, r+1);
    }
  }
  
  return 0;
}
