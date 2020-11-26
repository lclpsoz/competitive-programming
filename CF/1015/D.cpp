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

ll n, k;
ll s;

int main () {
  scanf ("%lld %lld %lld", &n, &k, &s);
  if (k*(n-1) < s || k > s)
    printf ("NO\n");
  else {
    printf ("YES\n");
    int pos = 1;
    int aux = (int)(s/k);
    vector<int> vec;
    for (int i = 0; i < k; i++)
      vec.push_back (aux);
    aux = (int)(s - (k*aux));
    for (int i = 0; i < aux; i++)
      ++vec[i];
    bool dir = true;
    for (int x : vec) {
      if (dir)
	pos += x;
      else
	pos -= x;
      dir = !dir;
      printf ("%d ", pos);
    }
    putchar ('\n');
  }
  
  return 0;
}
