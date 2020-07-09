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

string str[6];

int main () {
  ios::sync_with_stdio(false);
  cin.tie (0);
  cin >> str[0];
  int k;
  cin >> k;
  pii ans = {-1, -1};
  for (int i = 1; i <= 5; i++) {
    cin >> str[i];
    pii aux = {i, k};
    for (int j = 0; j < min (len (str[0]), len (str[i])); j++)
      if (str[0][j] != str[i][j])
	aux.y--;
    if (aux.y > ans.y)
      ans = aux;
  }
  if (ans.y == -1)
    printf ("-1\n");
  else
    printf ("%d\n%d\n", ans.x, k-ans.y);
  
  return 0;
}
