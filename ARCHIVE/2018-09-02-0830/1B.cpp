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

const int N = 200;

int n;
char str[N], a[N], b[N];

int main ()
{
  scanf ("%d", &n);
  while (n--) {
    scanf ("%s", str);
    int p = 0;
    int c;
    while (str[p] >= 'A' && str[p] <= 'Z') ++p;
    c = p;
    while (str[p] >= '0' && str[p] <= '9') ++p;
    int col, row;
    col = row = 0;
    if (str[p] == '\0') {
      int aux = 1;
      for (int i = c-1; i >= 0; i--) {
	col += (str[i]-'A'+1)*aux;
	aux *= 26;
      }
      printf ("R%sC%d\n", str+c, col);
    } else {
      sscanf (str, "R%[0-9]C%d", a, &col);
      p = 0;
      while (col) {
	b[p] = ((col-1)%26)+'A';
	col = (col-1)/26;
	p++;
      }

      for (int i = p-1; i >= 0; i--)
	putchar (b[i]);
      printf ("%s\n", a);
    }
  }

  return 0;
}
