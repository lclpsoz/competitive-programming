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

const int R = 1010;

int n, r;
int arr[R];
vector<pii> prod[3];

int func (int p1, int p2) {
  for (int i = 1; i <= r; i++)
    arr[i] = -1;
  arr[0] = 0;
  for (pii p : prod[p1]) {
    //printf ("%d %d\n", p.x, p.y);
    int w = p.y;
    int qnt = p.x;
    for (int i = r; i >= w; i--)
      if (arr[i-w] != -1)
	  arr[i] = max (arr[i], arr[i-w]+qnt);
  }
  /*for (int i = 0; i <= r; i++) {
    printf ("%2d ", arr[i] == INF ? -1 : arr[i]);
    }*/
  //putchar ('\n');
  for (pii p : prod[p2]) {
    int w = p.y;
    int qnt = p.x;
    for (int i = r; i >= w; i--)
      if (arr[i-w] != -1)
	  arr[i] = max (arr[i], arr[i-w]+qnt);
  }
  int ret = 0;
  for (int i = 0; i <= r; i++) {
    //printf ("%2d ", arr[i] == INF ? -1 : arr[i]);
    ret = max (ret, arr[i]);
  }
  //putchar ('\n');
  
  return ret;
  
}

int main ()
{
  int qnt, w, pos;
  char opt;
  scanf ("%d %d", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf ("%d %c %d", &qnt, &opt, &w);
    if (opt == 'B')
      pos = 0;
    else if (opt == 'C')
      pos = 1;
    else
      pos = 2;
    prod[pos].pb ({qnt, w});
  }
  printf ("%d\n", max (func (0, 1), max (func (0, 2), func (1, 2))));
  
  return 0;
}
