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

int n;
char str[50];

int main () {
  while (scanf ("%d", &n) != EOF) {
    while (n--) {
      scanf ("%s", str);
      int ans = 0;
      int aux = 1;
      for (int i = strlen (str)-1; i >= 0; i--) {
	if (str[i] == '1')
	  ans+=aux;
	aux <<= 1;
      }
      putchar (ans);
    }
    putchar ('\n');
  }
  
  return 0;
}
