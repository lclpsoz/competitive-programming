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

int n, m, x;
vector<pair<int, string>> vec;
vector<string> tim[1010];
string str;

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  while (n--) {
    cin >> str >> x;
    vec.push_back ({-x, str});
  }

  sort (vec.begin(), vec.end());
  int i = 0;
  for (auto p : vec) {
    tim[i].push_back (p.y);
    i = (i+1)%m;
  }
  for (int i = 0; i < m; i++) {
    cout << "Time " <<  i+1 << '\n';
    sort (tim[i].begin(), tim[i].end());
    for (string s : tim[i])
      cout << s << '\n';
    cout << '\n';
  }
  
  return 0;
}
