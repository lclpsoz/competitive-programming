#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second

using pii = pair<int, int>;
const int MOD = 1e9+7;

int t, n;
pair<int, int> arr[3030];

int main () {
  
  scanf ("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf ("%d", &n);
    arr[i] = {n, i};
  }
  sort (arr, arr+t);

  int p = 0;
  int x = 0, y = 1, z;
  if (arr[p].x == 1)
    ++p;
  for (int i = 2; p < t; i++) {
    z = x+y;
    if (z > MOD)
      z -= MOD;
    while (i == arr[p].x) {
      arr[p].x = z;
      ++p;
    }
    x = y;
    y = z;
  }
  for (pii &pp : arr)
    swap (pp.x, pp.y);
  sort (arr, arr+t);
  for (int i = 0; i < t; i++)
    printf ("%d\n", arr[i].y);

  return 0;
}
