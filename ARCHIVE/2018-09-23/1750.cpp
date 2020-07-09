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

const int N = 1010;

int n;
int arr[N];

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", &arr[i]);
  sort (arr, arr+n);

  int s1, s2;
  s1 = s2 = 0;
  for (int i = 0; i < n; i+=2)
    s1 += min (abs(arr[i]-arr[i+1]), 24-abs(arr[i]-arr[i+1]));
  for (int i = 1; i < n-1; i+=2)
    s2 += min (abs(arr[i]-arr[i+1]), 24-abs(arr[i]-arr[i+1]));
  s2 += min (abs(arr[n-1]-arr[0]), 24-abs(arr[n-1]-arr[0]));

  printf ("%d\n", min (s1, s2));
  
  return 0;
}
