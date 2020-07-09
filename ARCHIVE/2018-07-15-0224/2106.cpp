#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXP = 1<<18;

int n;
int mat[19][19];
int dp[19][MAXP];

int opt = 0;
int calls = 0;
int func (int jog, int time, int qnt) {
  calls++;
  if (qnt == n)
    return 0;
  int &r = dp[jog][time];
  if (r != -1) return r;
  opt++;
  r = INF;
  for (int i = 0; i < n; i++)
    if (!(time & 1 << i))
      r = min (r, func (i, time | (1 << i), qnt+1) + mat[i][qnt]);

  return r;
}

int main ()
{
  while (scanf ("%d", &n), n) {
    opt = 0;
    calls = 0;
    memset (dp, -1, sizeof (dp));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	scanf ("%d", &mat[i][j]);
    printf ("%d\n", func (0, 0, 0));
    printf ("$$$ %d | %d\n", opt, calls);
  }

  return 0;
}
