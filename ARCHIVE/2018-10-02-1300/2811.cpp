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

const llu MOD = 1e9+7;
inline llu mod (llu x, llu m = MOD) {
  return (((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2020;

int n;
int fat[N];
int qnt[70];

bool bin_newton_even (int a, int b) {
  return (fat[a] > (fat[b]+fat[a-b]));
}

int main () {
  fat[0] = 0;
  for (int i = 1; i < N; i++) {
    for (int j = 2; i/j > 0; j<<=1)
      fat[i] += i/j;
  }

  llu x;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%llu", &x);
    int p = 0;
    while (x) {
      if (x&1)
	qnt[p]++;
      ++p;
      x >>= 1;
    }
  }

  llu ans = 0;
  x = 0;
  // Subsets of size 1
  for (int i = 0; i < 64; i++)
    if (qnt[i]&1)
      x |= (1LLU << i);
  ans = mod (x);
  //printf ("%d\n", ans);
  // Subsets of size [2..n-1]
  for (int i = 2; i < n; i++) {
    x = 0;
    for (int j = 0; j < 64; j++)
      if (qnt[j] == i  || (qnt[j] > i && !bin_newton_even (qnt[j], i)))
	x |= (1LLU<<j);
    ans = mod (ans + mod(x));
    //printf ("%d: %llu\n", i, ans);
  }
  if (n > 1) {
    // Subset of size n
    x = 0;
    for (int i = 0; i < 64; i++) {
      //printf ("%d: %d\n", i, qnt[i]);
      if (qnt[i] == n)
	x |= (1LLU << i);
    }
    ans = mod (ans + mod(x));
  }
  
  printf ("%llu\n", ans);
  
  return 0;
}
