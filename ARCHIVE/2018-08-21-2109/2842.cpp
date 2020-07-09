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
#define X real()
#define Y imag()
#define mp make_pair
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int INF = 1e9;
  
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

char a[1010], b[1010];
int dp[1010][1010];

int main ()
{
  scanf ("%s %s", a+1, b+1);
  int na = strlen (a+1);
  int nb = strlen (b+1);

  bool ok = false;
  if (a[1] == b[1]) {
    dp[1][1] = 1;
    ok = true;
  }
  else
    dp[1][1] = 2;
  bool aux = ok;
  for (int i = 2; i <= na; i++) {
    dp[i][1] = dp[i-1][1]+1;
    if (!aux && a[i] == b[1]) {
      dp[i][1]--;
      aux = true;
    }
  }
  aux = ok;
  for (int j = 2; j <= nb; j++) {
    dp[1][j] = dp[1][j-1]+1;
    if (!aux && a[1] == b[j]) {
      dp[1][j]--;
      aux = true;
    }
  }
  
  for (int i = 2; i <= na; i++)
    for (int j = 2; j <= nb; j++)
      if (a[i] == b[j])
	dp[i][j] = dp[i-1][j-1]+1;
      else
	dp[i][j] = min (dp[i-1][j], dp[i][j-1])+1;
  /*for (int i = 1; i <= na; i++) {
    for (int j = 1; j <= nb; j++)
      printf ("%2d ", dp[i][j]);
    putchar ('\n');
    }*/
  printf ("%d\n", dp[na][nb]);
  

  return 0;
}
