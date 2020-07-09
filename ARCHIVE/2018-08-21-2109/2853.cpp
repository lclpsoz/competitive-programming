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

int n, m;
char mat[1010][1010];
int val[1010][1010];

int main ()
{
  memset (mat, -1, sizeof (mat));
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf (" %c", &mat[i][j]);

  int aux;
  for (int i = 0; i < n; i++) {
    aux = INF;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '@')
	aux = 0;
      val[i][j] = aux;
      ++aux;
    }
    aux = INF;
    for (int j = m-1; j >= 0; j--) {
      if (mat[i][j] == '@')
	aux = 0;
      val[i][j] = min (val[i][j], aux);
      ++aux;
    }
  }
  for (int i = 0; i < m; i++) {
    aux = INF;
    for (int j = 0; j < n; j++) {
      if (mat[j][i] == '@')
	aux = 0;
      val[j][i] = min(val[j][i], aux);
      ++aux;
    }
    aux = INF;
    for (int j = n-1; j >= 0; j--) {
      if (mat[j][i] == '@')
	aux = 0;
      val[j][i] = min (val[j][i], aux);
      ++aux;
    }
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      //printf ("%2d ", val[i][j] >= INF ? -1 : val[i][j]);
      ans = max (ans, val[i][j]);
    }
    //putchar ('\n');
  }
    
  printf ("%d\n", ans >= INF ? -1 : ans);
  return 0;
}
