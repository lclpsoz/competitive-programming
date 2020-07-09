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

char c;
string str;
string base[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
map<char, char> mp;

int main () {
  scanf (" %c ", &c);
  cin >> str;

  if (c == 'L') {
    for (int j = 0; j < 3; j++) {
      string s = base[j];
      for (int i = 0; i < len (s)-1; i++)
	mp[s[i]] = s[i+1];
    }
  } else {
    for (int j = 0; j < 3; j++) {
      string s = base[j];
      for (int i = 1; i < len (s); i++)
	mp[s[i]] = s[i-1];
    }
  }
  for (int i = 0; i < len (str); i++)
    putchar (mp[str[i]]);
  putchar ('\n');
  

  return 0;
}
