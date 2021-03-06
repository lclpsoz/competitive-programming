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

vector<int> vec;
vector<int> aux;

int n, x;

int main () {
  while (scanf ("%d", &n) != EOF) {
    while (n--) {
      scanf ("%d", &x);
      vec.push_back (x);
    }
    for (int i = 0; i < len (vec); i++) {
      auto it = lower_bound (aux.begin(), aux.end(), vec[i]);
      if (it == aux.end())
	aux.push_back (vec[i]);
      else
	*it = vec[i];
    }
    printf ("%d\n", len (aux));
    aux.clear();
    vec.clear();
  }

  return 0;
}
