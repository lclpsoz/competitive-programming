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

const int N = 1e4+10, M = 2e6+100;

int t, n;
int pali[M];
pii ans[N];
char opr[] = "*+-x/";

bool is_pali (int x) {
  if (pali[x] == 1)
    return true;
  else if (pali[x] == 2)
    return false;
  int val = x;
  vector<int> vec;
  while (x) {
    if (x&1)
      vec.push_back (1);
    else
      vec.push_back (0);
    x >>= 1;
  }
  for (int i = 0; i < len (vec)/2; i++)
    if (vec[i] != vec[len(vec)-i-1]) {
      pali[val] = 2;
      return false;
    }
  pali[val] = 1;
  return true;
}

int apply_opr (int v, char c, int x) {
  if (c == '+')
    return v+x;
  else if (c == '-')
    return v-x;
  else if (c == 'x')
    return v*x;
  else
    return v/x;
}

int main () {
  for (int i = 1; i < N; i++)
    if (is_pali (i))
      ans[i].x = 0;
    else
      for (int j = 1; j < 200 && !ans[i].x; j++)
	for (int k = 1; k <= 4; k++)
	  if (is_pali (apply_opr (i, opr[k], j))) {
	    ans[i] = {k, j};
	    break;
	  }
  
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);
    printf ("%c", opr[ans[n].x]);
    if (ans[n].x) {
      printf (" %d", ans[n].y);
    }
    putchar ('\n');
  }
  
  return 0;
}
