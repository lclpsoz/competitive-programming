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

const int N = 1e6+100;

int n;
vector<int> vec;
bool not_prime[N];

int main () {
  not_prime[0] = not_prime[1] = true;
  for (int i = 2; i*i < N; i++)
    if (!not_prime[i])
      for (int j = i*i; j < N; j+=i)
	not_prime[j] = true;

  int t;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);
    int x;
    vec.clear();
    while (n--) {
      scanf ("%d", &x);
      vec.push_back (x);
    }
    sort (vec.begin(), vec.end());
    int ans = 0;
    while (ans < len (vec) && vec[ans] == ans+1)
      ++ans;

    if (ans)
      while (not_prime[ans+1])
	++ans;
    printf ("%d\n", ans);
  }
  
  
  return 0;
}
