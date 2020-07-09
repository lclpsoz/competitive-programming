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

const int N = 5e3+10;

int n;
char a1[N], a2[N];
int dp[2][N];

int main () {
  scanf ("%s %s", a1+1, a2+1);
  int n = strlen (a1+1)+1;
  int m = strlen (a2+1)+1;
  for (int i = 1; i < n; i++) {
    int p = i&1;
    for (int j = 1; j < m; j++) {
      dp[p][j] = dp[!p][j-1] + (a1[i] == a2[j]);
      //printf ("%d |%d| ", dp[!p][j-1]+(a1[i]==a2[j]), dp[p][j]);
      dp[p][j] = max(dp[p][j], max (dp[!p][j], dp[p][j-1]));
      //printf ("[%d] ", dp[p][j]);
    }
    //putchar ('\n');
  }
  /*for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++)
      printf ("%d ", dp[i][j]);
    putchar ('\n');
    }*/

  printf ("%d\n", dp[(n-1)&1][m-1]);
  
  return 0;
}
