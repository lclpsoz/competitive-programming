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

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x;
  while (cin >> x) {
    vector<string> vec;
    while (cin >> str, str[0] == 'P') {
      string aux;
      cin >> aux;
      str += " " + aux;
      vec.push_back (str);
    }
    sort (vec.begin(), vec.end());
    for (string s : vec)
      cout << s << '\n';
    cout << '\n';
  }
  
  return 0;
}
