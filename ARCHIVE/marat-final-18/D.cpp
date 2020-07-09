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

string func (string str) {
  string name, domain;
  name = domain = "";
  bool plus = false;
  bool nameB = true;
  for (int i = 0; i < len (str); i++)
    if (nameB && str[i] != '@') {
      if (str[i] != '.' && !plus && str[i] != '+')
	name += str[i];
      else if (str[i] == '+')
	plus = true;
    }
    else {
      nameB = false;
      domain += str[i];
    }
  return name + domain;
}

int main () {
  set<string> conj;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    conj.insert (func (str));
  }

  cout << len (conj) << '\n';

  return 0;
}
