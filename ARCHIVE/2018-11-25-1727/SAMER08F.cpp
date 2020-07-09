#include "bits/stdc++.h"
using namespace std;

int ans[105];

int main () {
  for (int i = 1; i <= 100; i++)
    ans[i] = ans[i-1] + i*i;

  int n;
  while (scanf ("%d", &n), n)
    printf ("%d\n", ans[n]);
  
  return 0;
}
