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

int t, r, m, n, total;
string ori[110], now[110];

int main () {
  scanf ("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    total = 0;
    scanf ("%d", &r);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
      cin >> ori[i];
      //cout << ori[i] << '\n';
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
      cin >> now[i];
      if (i >= n)
	ori[i] = "";
    }
    //printf ("%d %d\n", n, m);
    if (n > m)
      total = n-m;
    for (int i = 0; i < m; i++)
      if (ori[i] == "")
	total += 5;
      else if (ori[i] != now[i])
	total += 2;
    total *= r;
    
    printf ("Caso #%d: R$ %d,%02d\n", tt, total/2, (total%2)*50);
  }
  
  return 0;
}
