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

using pp = pair<ll, ll>;
const int N = 1e4+10;

int t, n;
vector<int> vec, aux;
int arr[N];

ll mdc (ll x, ll y) {
  if (x == 0) return y;
  return mdc (y%x, x);
}

ll mmc (ll x, ll y) {
  return x*y / mdc (x, y);
}
// True if x > y
bool comp (pp x, pp y) {
  ll mc = mmc (x.y, y.y);
  //cout << x.x << '\n';
  x.x *= (mc/x.y);
  y.x *= (mc/y.y);
  //cout << x.x << ' ' << y.x << '\n';
  return x.x > y.x; // Compare with same denominator
}

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);
    while (n--) {
      int x;
      scanf ("%d", &x);
      ++arr[x];
      vec.push_back (x);
    }
    
    bool ans = false;
    for (int i = 0; i < len (vec); i++) {
      if (arr[vec[i]] >= 4) {
	ans = true;
	int v = vec[i];
	printf ("%d %d %d %d\n", v, v, v, v);
	break;
      } else if (arr[vec[i]] >= 2)
	aux.push_back (vec[i]);
      arr[vec[i]] = 0;
    }
    for (int i = 0; i < len (vec); i++)
      arr[vec[i]] = 0;
    if (!ans) {
      sort (aux.begin(), aux.end());
      int a, b;
      pp best = {1e9, 1};
      for (int i = 1; i < len (aux); i++) {
	pp now = {2*aux[i] + 2*aux[i-1],
		  aux[i]*aux[i-1]};
	now.x *= now.x;
	//cout << now.x << ' ' << now.y << '\n';
	if (comp (best, now)) {
	  best = now;
	  a = aux[i];
	  b = aux[i-1];
	}
      }

      printf ("%d %d %d %d\n", a, a, b, b);
    }
    
    vec.clear();
    aux.clear();
  }

  return 0;
}
