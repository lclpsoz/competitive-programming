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

const int P = 31650;

bool not_prime[P];
vector<ll> primes;
pii factors[110];

int mdc (int a, int b) {
  if (b == 0) return a;
  return mdc (b, a%b);
}

void sieve () {
  int i = 2;
  for (; i*i < P; i++) {
    for (int j = i*i; j < P; j += i)
      not_prime[j] = true;
    primes.push_back (i);
  }
  while (i < P) {
    if (!not_prime[i])
      primes.push_back (i);
    ++i;
  }
}

ll pow_ll (int b, int p) {
  ll r = 1;
  for (int i = 0; i < p; i++)
    r *= b;
  return r;
}

int main () {
  sieve();
  
  int a, b;
  scanf ("%d %d", &a, &b);
  ll x = mdc (a, b);
  int p = 0, pos = 0;
  while (x > 1 && (primes[p]*primes[p]) <= x) {
    if (x % primes[p] == 0) {
      factors[pos].x = primes[p];
      while (x % primes[p] == 0) {
	x /= primes[p];
	++factors[pos].y;
      }
      ++pos;
    }
    ++p;
  }
  if (x > 1) {
    factors[pos] = {x, 1};
    ++pos;
  }
  ll ans = 1;
  for (int i = 0; i < pos; i++) {
    //printf ("%d %d\n", factors[i].x, factors[i].y);
    ans *= pow_ll (factors[i].x, (factors[i].y+1)/2);
  }
  printf ("%d\n", ans);
  
  return 0;
}
