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

int n, mid;
map<int, pair<ll, ll>> ans;

ll mdc (ll a, ll b) {
  if (b == 0) return a;
  return mdc (b, a%b);
}

ll func (int d) {
  int now = n/d;
  int aft = (n/(d+1)) + 1; // Can't count that
  if (now <= mid || aft <= mid)
    return 0;
  int qnt = now - aft + 1;
  
  int stren = n%now;
  ll pa = (qnt*1LL*(qnt+1))/2;
  pa *= d;
  pa -= qnt*(d-stren);
  return pa;
}

int main () {
  while (scanf ("%d", &n) != EOF) {
    pair<ll, ll> val;;
    mid = sqrt (n);
    for (int i = 2; i <= mid; i++)
      val.x += (n%i);
    //if (n > 5 && n&1)
    //  val.x += n%(mid+1);
    for (int d = 1; d <= mid; d++)
      val.x += func (d);
    //printf ("%d: %lld\n", n, val.x);

    val.y = n*1LL*n;
    ll md = mdc (val.x, val.y);
    val = {val.x/md, val.y/md};
    printf ("%lld/%lld\n", val.x, val.y);
  }
  
  return 0;
}
