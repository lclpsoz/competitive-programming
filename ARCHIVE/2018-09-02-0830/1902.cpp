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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9 + 7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+10;

string s1, s2;
unordered_map<string, int> mp;
int adj[N];
char vert[N];

bool dfs (int v) {
  if (vert[v] == 'G')
    return true;
  if (adj[v] == 0 || vert[v] == 'B')
    return false;
  vert[v] = 'G';
  bool r = dfs (adj[v]);
  vert[v] = 'B';
  return r;
}

int main () {
  int p = 0;
  int u, v;
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> s1 >> s2) {
    if (!mp.count (s1)) {
      v = ++p;
      mp[s1] = v;
    } else
      v = mp[s1];
    if (!mp.count (s2)) {
      u = ++p;
      mp[s2] = u;
    } else
      u = mp[s2];
    adj[v] = u;
  }

  int ans = 0;
  for (int i = 1; i <= p; i++)
    if (vert[i] == '\0')
      ans += dfs (i);
  cout << ans << '\n';
  
  return 0;
}
