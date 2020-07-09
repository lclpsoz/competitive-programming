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

const int N = 1e6+10;

int t;
int a, b, k;
int dp[N];
bool not_prime[N];
vector<int> primes;

int func (int x) {
  //printf ("%d %d\n", x, !not_prime[x]);
  int &r = dp[x];
  if (r != -1)
    return r;

  if (!not_prime[x])
    return r = 1;
  int p = 0, val = 0;
  while (x > 1 && primes[p] < x) {
    if (x % primes[p] == 0) {
      val += primes[p];
      while (x % primes[p] == 0)
	x /= primes[p];
    }
    ++p;
  }
  if (x > 1)
    val += x;

  return r = func (val) + 1;
}

int main () {
  for (int i = 2; i*i < N; i++)
    if (!not_prime[i])
      for (int j = i*i; j < N; j+=i)
	not_prime[j] = true;
  for (int i = 2; i < N; i++)
    if (!not_prime[i])
      primes.push_back (i);

  int maxi = 0;
  memset (dp, -1, sizeof dp);
  for (int i = 1e6; i >= 1; i--) {
    maxi = max (maxi, func (i));
    //printf ("%d %d\n", i, maxi);
  }
  printf ("%d\n", maxi);
  
  scanf ("%d", &t);
  while (t--) {
  }
  
  return 0;
}
