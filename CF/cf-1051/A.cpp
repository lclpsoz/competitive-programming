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

int t;
string str;

int main () {
  cin >> t;
  while (t--) {
    cin >> str;
    vector<int> low, high, dig;
    for (int i = 0; i < len (str); i++)
      if (str[i] >= 'a' && str[i] <= 'z')
	low.push_back (i);
      else if (str[i] >= 'A' && str[i] <= 'Z')
	high.push_back (i);
      else
	dig.push_back (i);

    if (len (high) == 0) {
      if (len (low) > 1) {
	str[low.back()] = 'A';
	low.pop_back ();
      } else if (len (dig) > 1) {
	str[dig.back()] = 'A';
	dig.pop_back();
      }
    }
    if (len (low) == 0) {
      if (len (high) > 1) {
	str[high.back()] = 'a';
	high.pop_back ();
      } else if (len (dig) > 1) {
	str[dig.back()] = 'a';
	dig.pop_back();
      }
    }
    if (len (dig) == 0) {
      if (len (low) > 1) {
	str[low.back()] = '1';
	low.pop_back ();
      } else if (len (high) > 1) {
	str[high.back()] = '1';
	high.pop_back();
      }
    }
    cout << str << '\n';
  }

  return 0;
}
