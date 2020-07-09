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
string str1, str2;

int diff (int x) {
  if (n&1 && x == n/2)
    return (str1[x] != str2[x]);

  char a = str1[x];
  char b = str1[n-x-1];
  char c = str2[x];
  char d = str2[n-x-1];
  
  if ((a == c && b == d) ||
      (a == d && b == c) ||
      (a == b && c == d))
    return 0;

  if (a == c || a == d || b == c || b == d || c == d)
    return 1;
  return 2;
}

int main () {
  scanf ("%d", &n);
  cin >> str1 >> str2;
  int ans = 0;
  for (int i = 0; i <= (n-1)/2; i++) {
    ans += diff (i);
    //printf ("%d\n", ans);
  }
  printf ("%d\n", ans);
  
  return 0;
}
