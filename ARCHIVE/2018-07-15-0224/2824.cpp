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

const int MAXN = 5e3+10;

char arr[MAXN], arr2[MAXN];
int ans;
int dp[2][MAXN];

int lcs (int n, int m) {
  //printf ("%d %d\n", n, m);
  for (int ii = 1, i = 1; arr[ii] != '\0'; ++ii, i = !i)
    for (int j = 1; arr2[j] != '\0'; j++) {
      dp[i][j] = max (dp[!i][j], dp[i][j-1]);
      if (arr[ii] == arr2[j])
	dp[i][j] = max (dp[i][j], dp[!i][j-1]+1);
    }
  return dp[n%2][m];
}

int main ()
{
  scanf ("%s %s", arr+1, arr2+1);
  printf ("%d\n", lcs (strlen (arr+1), strlen(arr2+1)));
  
  return 0;
}
