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
int dp[MAXN][MAXN];

int lcs (int i, int j) {
  if (arr[i] == '\0' || arr2[j] == '\0') return 0;
  int &r = dp[i][j];
  if (r != -1) return r;
  r = 0;
  if (arr[i] == arr2[j])
    r = 1 + lcs (i+1, j+1);
  else
    r = max (lcs (i+1, j), lcs (i, j+1));

  return r;
}

int main ()
{
  memset (dp, -1, sizeof (dp));
  scanf ("%s %s", arr, arr2);
  printf ("%d\n", lcs (0, 0));
  
  return 0;
}
