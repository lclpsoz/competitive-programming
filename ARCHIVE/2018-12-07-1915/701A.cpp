#include "bits/stdc++.h"
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

const int N = 110;

int sum;
int arr[N];

int main () {
  int n;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d", &arr[i]);
    sum += arr[i];
  }

  int valInd = sum/(n/2);
  int p = 0;
  for (int i = 0; i < (n/2); i++) {
    while (arr[p] == -1)
      ++p;
    for (int j = p+1; j < n; j++)
      if (arr[j]+arr[p] == valInd) {
	printf ("%d %d\n", j+1, p+1);
	arr[j] = -1;
	break;
      }
    ++p;
  }

  return 0;
}
