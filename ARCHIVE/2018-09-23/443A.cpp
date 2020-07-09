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

set<string> s;
char c;
string str;
char str1[1010];

int main () {
  ios::sync_with_stdio(false);
  cin.tie (0);
  getline (cin, str);
  for (int i = 0; i < str.size(); i++)
    str1[i] = str[i];
  
  char *ss = strtok (str1, " {},");
  while (ss != NULL) {
    s.insert (ss);
    ss = strtok (NULL, " {},");
  }
  printf ("%lu\n", s.size());
  
  return 0;
}
