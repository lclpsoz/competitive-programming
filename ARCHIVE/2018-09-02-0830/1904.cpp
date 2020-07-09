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

const int MOD = 1e9 + 7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e7+10;

int a, b;
int n, k;
bool not_prime[N];

int qnt2 (int x) {
  int r = 0;
  for (int i = 2; i <= x; i*=2)
    r += x/i;
  return r;
}

int main () {
  int acu = 0;
  scanf ("%d %d", &a, &b);
  if (a > b)
    swap (a, b);
  if (a == b)
    printf ("?\n");
  else {
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i*i < N; i++)
      if (!not_prime[i])
	for (int j = i*i; j < N; j+=i)
	  not_prime[j] = true;
    n = 0;
    for (int i = a; i <= b; i++)
      n += !not_prime[i];
    k = b-a;
    int s = k+n-1;
    //printf ("%d %d\n", s, n);
    //printf ("%d %d %d\n", qnt2[s], qnt2[k], qnt2[s-k]);
    if (n != 0 && qnt2(s)-qnt2(k)-qnt2(s-k) == 0)
      printf ("Alice\n");
    else
      printf ("Bob\n");
  }
  
  return 0;
}
