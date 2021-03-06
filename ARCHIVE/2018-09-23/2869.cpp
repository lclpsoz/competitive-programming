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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = sqrt(1e5+100);

bool not_prime[N];
vector<int> factors;

int pow_mod (int v, int p) {
  int r = 1;
  while (p) {
    if (p&1)
      r = mod (r*1LL*v);
    p >>= 1;
    v = mod (v*1LL*v);
  }

  return r;
}

int brute[120];

int main () {
  
  not_prime[0] = not_prime[1] = true;
  for (int i = 2; i*i < N; i++)
    if (!not_prime[i])
      for (int j = i*i; j < N; j+=i)
	not_prime[j] = true;

  vector<int> primes;
  for (int i = 2; i < N; i++)
    if (!not_prime[i])
      primes.push_back (i);
  for (int i = 1; i < 1e5; i++) {
    int qnt = 1;
    int val = i;
    int p = 0;
    while (val > 1 && p < len (primes)) {
      int aux = 1;
      while (val % primes[p] == 0) {
	++aux;
	val /= primes[p];
      }
      ++p;
      //printf ("%d\n", p);
      qnt *= aux;      
    }
    if (val > 2)
      qnt *= 2;
    if (qnt < 100 &&!brute[qnt])
      brute[qnt] = i;
  }
  
  int qnt;
  ll n;
  scanf ("%d", &qnt);
  while (qnt--) {
    scanf ("%lld", &n);
    int aux = brute[n];
    //printf ("%d ", brute[n]);
    int p = 0;
    while (n > 1) {
      while (n%primes[p] == 0) {
	factors.push_back (primes[p]);
	n /= primes[p];
      }
      ++p;
    }

    int ans = 1;
    for (int i = len(factors)-1, j = 0; i >= 0; --i, ++j) {
      //printf ("%d ** %d\n", primes[j], factors[i]-1);
      ans = mod (ans * 1LL * pow_mod (primes[j], factors[i]-1));
    }

    if (aux > 2 && aux < ans)
      printf ("%d\n", aux);
    else
      printf ("%d\n", ans);
    factors.clear();
  }
  
  return 0;
}
