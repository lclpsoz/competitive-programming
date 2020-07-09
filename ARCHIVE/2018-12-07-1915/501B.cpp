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

int n;
string str1, str2;
map<string, string> mp;
set<string> notNew;
vector<string> ans;

int main () {
  cin.tie(0);
  ios::sync_with_stdio (false);
  cin >> n;
  while (n--) {
    cin >> str1 >> str2;
    if (notNew.count (str1) == 0)
      ans.push_back (str1);
    mp[str1] = str2;
    notNew.insert (str2);
  }

  cout << len (ans) << '\n';
  for (string old : ans) {
    string now = old;
    while (mp.count (now) == 1)
      now = mp[now];
    cout << old << ' ' << now << '\n';    
  }

  return 0;
}
