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

string str;

bool is_v (char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  return false;
}

int main () {
  cin >> str;
  int qnt_v = 0;
  for (int i = 0; i < str.size(); i++) {
    char c = str[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      ++qnt_v;
  }
  if (is_v (str[str.size()-1]) && !is_v (str[0]))
    printf ("0\n");
  else {
    if (qnt_v & 1) {
      int i = len (str) - 1;
      if (is_v(str[i]))
	--i;
      int qnt_c = 0;
      for (; i >= 0 && !is_v (str[i]); --i)
	++qnt_c;
      printf ("%d\n", qnt_c+1);      
    } else {
      int i = 0;
      if (is_v (str[0]))
	++i;
      int qnt_c = 0;
      for (; i < len (str) && !is_v (str[i]); i++)
	++qnt_c;
      printf ("%d\n", qnt_c+1);
    }
  }
  
  return 0;
}
