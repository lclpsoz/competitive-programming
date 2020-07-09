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

const int N = 1010;

int n, m;
int l;
int car[N][N], moto[N][N];
char c;

int main ()
{
  scanf ("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf (" %c", &c);
      car[i][j] = car[i-1][j] + car[i][j-1] - car[i-1][j-1];
      moto[i][j] = moto[i-1][j] + moto[i][j-1] - moto[i-1][j-1];
      if (c == 'C')
	car[i][j]++;
      else
	moto[i][j]++;
    }
  /*for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf ("%d ", car[i][j]);
    }
    putchar ('\n');
    }*/
  scanf ("%d", &l);
  int ans = -1;
  for (int i = l; i <= n; i++) {
    for (int j = l; j <= m; j++) {
      int a = car[i][j] - car[i-l][j] - car[i][j-l] + car[i-l][j-l];
      int b = moto[i][j] - moto[i-l][j] - moto[i][j-l] + moto[i-l][j-l];
      //printf ("(%d, %d): %d %d\n", i, j, a, b);
      if (a && b)
	ans = max (ans, 25*a+12*b);
    }
  }

  printf ("%d\n", ans);

  return 0;
}
