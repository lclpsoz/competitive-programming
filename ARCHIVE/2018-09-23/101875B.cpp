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

const int N = 5e5+10;

int n;
char t[2*N], p[N];
int z[2*N];

void f_z () {
  for (int i = 1, l = 0, r = 0; i < 2*n; ++i) {
    if (i <= r) z[i] = min (r-i+1, z[i-l]);
    while (i+z[i] < 2*n && t[z[i]] == t[i+z[i]])
      ++z[i];
    if (i+z[i]-1 > r)
      l = i, r = i+z[i]-1;
  }
}

bool ugly () {
  for (int i = 1; t[i] != '\0'; i++)
    if (z[i]+i < 2*n && t[z[i]+i] < t[z[i]])
      return false;

  return true;
}

int main () {
  scanf ("%d", &n);
  scanf ("%s", p);
  int i = 0;
  for (; p[i] != '\0'; i++)
    t[i] = p[i];
  for (int j = 0; p[j] != '\0'; j++)
    t[i++] = p[j];
  //printf ("%s\n", t);
  f_z ();
  //for (int i = 0; i < 2*n; i++)
  //  printf ("%d: %d\n", i, z[i]);
  printf ("%s\n", ugly () ? "Yes" : "No");
  
  return 0;
}
