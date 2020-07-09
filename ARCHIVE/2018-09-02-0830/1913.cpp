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

const int N = 1e3+10;

int n;
char str[30];
vector<pair<int, pair<int, int>>> vec;
int dp[N][1010][5];
int arr[] = {1, 2, 3, 0};

int func (int p, int r, int c) {
  //printf ("%*d %d %d\n", p+1, p, r, c);
  int &val = dp[p][r][c];
  if (val != -1)
    return val;
  if (p == n)
    return val = 0;
  if (vec[p].x < r && arr[vec[p].y.y] != c) {
    val = func (p+1, vec[p].x, vec[p].y.y) + vec[p].y.x;
  }
  val = max (val, func (p+1, r, c));
  return val;
}

int main () {
  int h, r, col;
  while (scanf ("%d", &n), n) {
    memset (dp, -1, sizeof (dp));
    vec.clear();
    for (int i = 0; i < n; i++) {
      scanf ("%d %d %s", &h, &r, str);
      if (str[3] == 'M')
	col = 0;
      else if (str[3] == 'A')
	col = 1;
      else if (str[3] == 'L')
	col = 2;
      else
	col = 3;
      vec.push_back ({r, {h, col}});
    }
    sort (vec.begin(), vec.end(), greater<pair<int, pii>>());
    printf ("%d centimetro(s)\n", func (0, 1e6, 10));
  }

  
  return 0;
}
