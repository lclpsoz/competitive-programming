#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, c;
char arr[103];
char mat[1003][103];
int dp[103][103];

int func (char *a, char *b) {
  int i, j;
  for (i = 1; a[i] != '\0'; ++i)
    for (j = 1; b[j] != '\0'; ++j) {
      if (a[i] == b[j])
	dp[i][j] = dp[i-1][j-1];
      else
	dp[i][j] = dp[i-1][j-1]+1;
      dp[i][j] = min (dp[i][j], min (dp[i-1][j]+1, dp[i][j-1]+1));
    }
  /*for (int ii = 0; ii <= i; ++ii) {
    for (int jj = 0; jj <= j; ++jj)
      printf ("%d ", dp[ii][jj]);
    putchar ('\n');
    }*/
  return dp[i-1][j-1];
}

int main ()
{
  for (int i = 0; i < 103; ++i)
    dp[i][0] = dp[0][i] = i;
  scanf ("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf ("%s", mat[i]+1);
  scanf ("%d", &c);
  int mini = INF;
  char *ans;
  while (c--) {
    scanf ("%s", arr+1);
    //printf ("%s\n", arr+1);
    mini = INF;
    for (int i = 0; i < n; ++i) {
      int x = func (arr, mat[i]);
      // printf ("[%d]\n", x);
      // printf ("\n[%d %d]\n", x, mini);
      if (x < mini) {
	ans = mat[i];
	// printf ("\n||%s||\n", ans+1);
	mini = x;
      }
    }
    printf ("%s", ans+1);
    if (c) putchar (' ');
  }
  putchar ('\n');

  return 0;
}
