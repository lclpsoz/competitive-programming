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

string s1, s2;
vector<char> v;

int main () {
  cin >> s1 >> s2;
  
  for (int i = 0; i < len (s1); i++)
    v.push_back (s1[i] == s2[i] ? '0' : '1');
  for (char c : v)
    putchar (c);
  putchar ('\n');
  
  return 0;
}
