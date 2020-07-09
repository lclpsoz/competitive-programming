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

const int MAXN = 1e3+10;

int n, q, ans;
char mat[MAXN][102], a[102], *b, *c;
int dp[105][105];

int edt (int i = 0, int j = 0) {
  //printf ("|||%d %d|||\n", i, j);
  int &r = dp[i][j];
  if (r != -1) return r;
  r = 0;
  if (a[i] == '\0' && b[j] == '\0')
    r = 0;
  else if (a[i] == '\0')
    r = edt (i, j+1)+1;
  else if (b[j] == '\0')
    r = edt (i+1, j)+1;
  else if (a[i] == b[j])
    r = edt (i+1, j+1);
  else
    r = min (edt (i+1, j), min (edt (i, j+1), edt (i+1, j+1))) + 1;

  //printf ("%d %d %d\n", i, j, r);
  return r;
}

int main ()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    scanf ("%s", mat[i]);
  
  cin >> q;
  while (q--) {
    scanf ("%s", a);
    ans = INF;
    for (int i = 0; i < n; i++) {
      b = mat[i];
      memset (dp, -1, sizeof (dp));
      int e = edt();
      //printf ("%s\t%d %d\n", b, i, e);
      if (e < ans) {
	ans = e;
	c = b;
      }
    }
    printf ("%s", c);
    if (q)
      putchar (' ');
  }
  putchar ('\n');

  return 0;
}
