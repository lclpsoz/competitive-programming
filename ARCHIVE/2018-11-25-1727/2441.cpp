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

int a, b, c;
int arr[1000];

int main () {
  for (int i = 0; i <= 600; i++)
    arr[i] = 1;
  scanf ("%d %d %d", &a, &b, &c);
  for (int i = a; i < a+200; i++)
    arr[i] = 0;
  for (int i = b; i < b+200; i++)
    arr[i] = 0;
  for (int i = c; i < c+200; i++)
    arr[i] = 0;
  int ans = 0;
  for (int i = 0; i < 600; i++)
    ans += arr[i];
  printf ("%d\n", ans*100);
  
  return 0;
}
