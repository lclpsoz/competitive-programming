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


int n;
string s1, s2;


int main () {
  cin >> n;
  cin >> s1 >> s2;
  
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      int p = i+1;
      for (; p < n; p++)
	if (s1[p] == s2[i])
	  break;
      if (p == n) {
	printf ("-1\n");
	return 0;
      }
      for (int j = p-1; j >= i; j--) {
	vec.push_back (j);
	swap (s1[j], s1[j+1]);
      }
    }
  }
  printf ("%d\n", len (vec));
  for (int z : vec)
    printf ("%d ", z+1);
  
  return 0;
}
