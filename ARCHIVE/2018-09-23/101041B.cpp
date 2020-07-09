#include <bits/stdc++.h>

using ll = long long;

const int N = 4e6+10;

int n;
ll x;
ll ans = 0;

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%lld", &x);
    ans ^= x;
  }
  printf ("%lld\n", ans);
	
  return 0;
}
