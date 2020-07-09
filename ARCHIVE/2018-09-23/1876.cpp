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

char arr[110];

int main () {
  while (scanf ("%s", arr) != EOF) {
    int acu = 0;
    int ans = 0;
    bool bef = true;
    for (int i = 0; arr[i] != '\0'; i++) {
      if (arr[i] == 'o')
	++acu;
      else {
	if (bef) {
	  bef = false;
	  ans = acu;
	} else
	  ans = max (ans, acu/2);
	acu = 0;
      }
    }
    ans = max (ans, acu);
    printf ("%d\n", ans);
  }
  
  return 0;
}
