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

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
vector<ll> vec;

int main () {
  ll x;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%lld", &x);
    vec.push_back (x);
  }
  sort (vec.begin(), vec.end());
  m = 1;
  int a[3];
  a[0] = vec[0];
  int lim = 1<<30;
  for (int i = 0; i < n && m < 3; i++) {
    //printf ("%lld\n", vec[i]);
    for (ll p = 1; p <= lim && m < 3; p <<= 1) {
      //printf ("    %lld\n", vec[i]+p);
      if (binary_search (vec.begin(), vec.end(), vec[i]+p)) {
	m = 2;
	a[0] = vec[i]; a[1] = vec[i]+p;
	if (binary_search (vec.begin(), vec.end(), vec[i]+p+p)) {
	  m = 3;
	  a[2] = vec[i]+2*p;
	}
      }
    }
  }

  printf ("%d\n", m);
  for (int i = 0; i < m; i++)
    printf ("%d ", a[i]);

  
  return 0;
}
