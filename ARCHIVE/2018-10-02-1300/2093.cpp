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

const int N = 1e5+10, P = 1<<18;

char arr[N];
bool vals[20][P];

int main () {
  scanf ("%s", arr);
  for (int sz = 1; sz <= 18; sz++) {
    int x = 0;
    for (int i = 0; i < sz; i++) {
      x <<= 1;
      if (arr[i] == '1')
	x |= 1;
    }
    vals[sz][x] = true;
    for (int i = sz; arr[i] != '\0'; i++) {
      x <<= 1;
      if (x & (1<<sz))
	x ^= 1<<sz;
      if (arr[i] == '1')
	x |= 1;
      vals[sz][x] = true;
    }
    for (int i = 0; i < (1<<sz); i++)
      if (!vals[sz][i]) {
	printf ("%d\n", sz);
	return 0;
      }
  }
  
  return 0;
}
