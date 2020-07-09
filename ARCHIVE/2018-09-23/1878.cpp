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
int a[4];

bool func () {
  vector<int> v(n+1, 1);
  set<int> s;
  while (v[n] == 1) {
    int aux = 0;
    for (int i = 0; i < n; i++)
      aux += a[i]*v[i];
    for (int i = 0; i < n; i++)
      printf ("%d ", v[i]);
    putchar ('\n');
    if (!s.insert (aux).y)
      return false;
    v[0]++;
    for (int i = 0; i < n; i++)
      if (v[i] > n) {
	v[i] = 1;
	++v[i+1];
      } else
	break;
  }

  return true;
}

int main () {
  while (scanf ("%d %d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++)
      scanf ("%d", &a[i]);
    if (func ())
      printf ("Lucky Denis!\n");
    else
      printf ("Try again later, Denis...\n");
  }

  
  return 0;
}
