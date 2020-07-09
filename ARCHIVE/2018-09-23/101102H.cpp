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
int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int C = 1e5+10;

int t;
int c, k;
char arr[C];

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &c, &k);
    k++;
    scanf ("%s", arr);
    int acu = 0, ans = 0;
    for (int i = 0; i < c; i++) {
      if (arr[i] == '1')
	acu = 0;
      else
	++acu;
      ans = max (acu, ans);
    }
    printf ("%s\n", ans >= k ? "yes" : "no");
  }
  
  return 0;
}
