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

const int N = 1e5+10;

char str[N];
int dp[N][3][2];
int n;

int func (int p, int acu, bool st) {
  int &r = dp[p][acu][st];
  if (r != -1)
    return r;
  //printf ("%d %d %d\n", p, acu, st);
  if (p == n)
    return INF;
  if (str[p] == 0 && !st)
    return r = func (p+1, acu, st)+1;
  else if (str[p]%2 == 0) {
    //printf ("even\n");
    r = min (func (p+1, (acu+str[p])%3, true),
	     func (p+1, acu, st)+1);
    if ((acu+(str[p]))%3 == 0)
      return r = min (r, n-p-1);
    else
      return r;
  }
  else {
    return r =
      min (func (p+1, (acu+str[p])%3, true),
	   func (p+1, acu, st)+1);
  }
}

int main ()
{
  int t;
  scanf ("%d", &t);
  while (t--) {
    memset (dp, -1, sizeof (dp));
    scanf ("%s", str);
    //printf ("\n|||||%s|||||\n", str);
    for (int i = 0; str[i] != '\0'; i++) {
      str[i] -= '0';
      n = i;
    }
    
    ++n;
    int f = func (0, 0, false);
    if (f >= INF)
      printf ("Cilada\n");
    else
      printf ("%d\n", f);
    /*for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++)
	printf ("[%2d %2d] ", dp[i][j][0] == INF ? -9 : dp[i][j][0],
		dp[i][j][1] == INF ? -9 : dp[i][j][1]);
      putchar ('\n');
      }*/
  }
  
  return 0;
}
