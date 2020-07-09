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

const int N = sqrt(1e9)+100;

vector<int> primes;
bool not_prime[N];

int main () {
  not_prime[0] = not_prime[1] = true;
  int p;
  for (p = 2; p*p < N; p++)
    if (!not_prime[p]) {
      for (int j = p*p; j < N; j+=p)
	not_prime[j] = true;
      primes.push_back (p);
    }
  while (p < N) {
    if (!not_prime[p])
      primes.push_back (p);
    ++p;
  }
  
  int t, l, r;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &l, &r);
    for (int i = l; i <= r; i++) {
      bool test = true;
      if (i < 2)
	test = false;
      for (int j = 0; j < len (primes) && primes[j]*primes[j] <= i; j++)
	if (i%primes[j] == 0) {
	  test = false;
	  break;
	}
      if (test)
	printf ("%d\n", i);
    }
    if (t) putchar ('\n');
  }

  return 0;
}
