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

const int N = 2e5+10;

int t;
int n, m;
char arr[N];
vector<int> vert, hori;

int check (int st, char c) {
  int r = 0;
  if (c == 'v')
    for (int x : vert) {
      if (x == -1 && st == 1)
	++r;
      else if (x == 1 && st == n)
	++r;
      else
	st += x;
    }
  else
    for (int x : hori) {
      if (x == -1 && st == 1)
	++r;
      else if (x == 1 && st == m)
	++r;
      else
	st += x;
    }

  return r;
}

int tern (char c) {
  //printf ("%c\n", c);
  int ret;
  // Vertical (n)
  if (c == 'v') {
    ret = min (check (1, 'v'), check (n, 'v'));
    int l = 1, r = n;
    int xl, xr, vxl, vxr;
    while (l < (r-2)) {
      xl = (2*l + r)/3;
      xr = (l + 2*r)/3;
      vxl = check (xl, 'v');
      vxr = check (xr, 'v');
      if (vxl >= vxr)
	l = xl;
      if (vxr >= vxl)
	r = xr;
    }
    for (int i = l; i <= r; i++)
      ret = min (ret, check (i, 'v'));

    // Horizontal
  } else {
    ret = min (check (1, 'h'), check (m, 'h'));
    int l = 1, r = m;
    int xl, xr, vxl, vxr;
    while (l < (r-2)) {
      xl = (2*l + r)/3;
      xr = (l + 2*r)/3;
      vxl = check (xl, 'h');
      vxr = check (xr, 'h');
      if (vxl >= vxr)
	l = xl;
      if (vxr >= vxl)
	r = xr;
    }
    for (int i = l; i <= r; i++)
      ret = min (ret, check (i, 'h'));
  }

  return ret;
}

int main () {
  scanf ("%d", &t);
  while (t--) {
    vert.clear();
    hori.clear();
    scanf ("%d %d %s", &n, &m, arr);
    for (int i = 0; arr[i] != '\0'; i++)
      if (arr[i] == '>' || arr[i] == '<')
	hori.push_back (((arr[i] == '>') ? 1 : -1));
      else
	vert.push_back (((arr[i] == 'v') ? 1 : -1));
    //printf ("|%d %d\n", len (vert), len (hori));
    printf ("%d\n", tern ('v') + tern ('h'));
  }
  
  return 0;
}
