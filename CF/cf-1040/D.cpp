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

char arr[10];
ll n, k;

int main () {
  srand (time(0));
  scanf ("%lld %lld", &n, &k);
  ll l, r;
  l = 1;
  r = n;
  bool now = true;
  while (true) {
    ll mid = (l+r)/2;
    if (now)
      printf ("%lld %lld\n", mid, r);
    else
      printf ("%lld %lld\n", l, mid);
    fflush (stdout);
    scanf ("%s", arr);
    if (arr[0] == 'B')
      return 0;
    else if (arr[0] == 'Y') {
      if (l == r)
	return 0;
      if (now) {
	l = max (1LL, mid-k);
	r = min (n, r+k);
      } else {
	l = max (1LL, l-k);
	r = min (n, mid+k);
      }

      if (r-l <= 44) {
	ll aux = l+((rand())%(r-l+1));
	printf ("%lld %lld\n", aux, aux);
	fflush (stdout);
	scanf ("%s", arr);
	if (arr[0] == 'Y')
	  return 0;
      
	l = max (1LL, l-k);
	r = min (n, r+k);
      }
    }
    else if (arr[0] == 'N') {
      //printf ("\t%lld %lld %lld\n", l, mid, r);
      if (now) {
	l = max (1LL, l-k);
	r = min (n, mid+k-1);
      } else {
	l = max (1LL, mid-k+1);
	r = min (n, r+k);
      }
    }
    now = !now;
  }
  
  return 0;
}
