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

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int t;

void func (int n) {
  vector<int> ans;
  for (int b = 2; b <= 16; b++) {
    vector<int> vec;
    int aux = n;
    if (n == 0)
      vec.push_back (0);
    while (aux) {
      vec.push_back (aux%b);
      aux /= b;
    }
    int sz = vec.size();
    bool now = true;
    for (int i = 0; i < sz/2; i++)
      if (vec[i] != vec[sz-1-i])
	now = false;
    if (now)
      ans.push_back (b);
  }
  if (ans.empty())
    printf("-1\n");
  else {
    for (int i = 0; i < ans.size(); i++) {
      printf ("%d", ans[i]);
      if (i < ans.size()-1)
	putchar (' ');
    }
    putchar ('\n');
  }
}

int main () {
  scanf ("%d", &t);
  while (t--) {
    int n;
    scanf ("%d", &n);
    func (n);
  }

  
  return 0;
}
