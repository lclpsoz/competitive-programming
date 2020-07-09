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

const int N = 1e6+10;

char a[N], ba[N];
int d, e;

void dig () {
  for (int i = 0; a[i] != '\0'; i++)
    d += a[i]-'0';
  while (d > 10) {
    int aux = d;
    d = 0;
    while (aux) {
      d += aux%10;
      aux /= 10;
    }
  }
}

int main ()
{
  //printf ("--------\n");
  
  scanf ("%s %s", a, ba);
  dig();
  //printf ("-----\n");
  for (int i = 0; ba[i] != '\0'; i++)
    e += ba[i]-'0';
  int y = e%3;
  int x = (ba[strlen(ba)-1]-'0')%2;

  //printf ("%d %d\n", x, y);
  if (x == 0) {
    if (y == 0)
      e = 0;
    else if (y == 1)
      e = 4;
    else if (y == 2)
      e = 2;
  } else {
    if (y == 0)
      e = 3;
    else if (y == 1)
      e = 1;
    else if (y == 2)
      e = 5;
  }
  int b = d;
  //printf ("%d %d\n", b, e);
  if (b == 1)
    printf ("%d\n", 1);
  else if (b == 2) {
    int ans[] = {2, 4, 8, 7, 5, 1};
    printf ("%d\n", ans[(e+5)%6]);
  }
  else if (b == 3) {
    if (e == 1)
      printf ("3\n");
    else
      printf ("9\n");
  }
  else if (b == 4) {
    int ans[] = {4, 7, 1};
    printf("%d\n", ans[((e+2)%3)]);
  }
  else if (b == 5) {
    int ans[] = {5, 7, 8, 4, 2, 1};
    printf ("%d\n", ans[((e+5)%6)]);
  }
  else if (b == 6) {
    if (e == 1)
      printf("6\n");
    else
      printf("9\n");
  }
  else if (b == 7) {
  int ans[] = {7, 4, 1};
  printf("%d\n", ans[(e+2)%3]);
  }
  else if (b == 8) {
    int ans[] = {8, 1};
    printf ("%d\n", ans[(e+1)%2]);
  }
  else if (b == 9) {
    printf("9\n");
  }


  return 0;
}
