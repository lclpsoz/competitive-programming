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

const int N = 1e2+10;

char arr1[N], arr2[N];
int dp[N][N];
int n, m;

// Edit distance bottom_up
int func () {
  for (int i = 0; i < N; ++i)
    dp[0][i] = dp[i][0] = i;
  dp[0][0] = 0;
  for (int i = 1; arr1[i] != '\0'; ++i) {
    for (int j = 1; arr2[j] != '\0'; ++j) {
      if (arr1[i] == arr2[j])
	dp[i][j] = dp[i-1][j-1];
      else
	dp[i][j] = dp[i-1][j-1]+1;
      dp[i][j] = min (min (dp[i][j], dp[i-1][j]+1), dp[i][j-1]+1);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++)
      printf ("%d ", dp[i][j] == INF ? 9 : dp[i][j]);
    putchar ('\n');
  }

  return dp[n][m];
}

int main ()
{
  scanf ("%s %s", arr1+1, arr2+1);
  n = strlen (arr1+1);
  m = strlen (arr2+1);
  printf ("ans: %d\n", func ());

  return 0;
}
