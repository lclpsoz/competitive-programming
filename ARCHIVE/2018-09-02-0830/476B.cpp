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

int n;
char str[20];
int pos[110];

void func (int p, int now) {
  if (str[p] == '\0')
    ++pos[now+20];
  else if (str[p] == '?') {
    func (p+1, now+1);
    func (p+1, now-1);
  }
  else
    func (p+1, now + ((str[p] == '+') ? 1 : -1));
}

int main ()
{
  scanf ("%s", str);
  int p = 0;
  for (int i = 0; str[i] != '\0'; i++)
    if (str[i] == '+') ++p;
    else --p;
  scanf ("%s", str);
  n = strlen (str);
  func (0, 0);
  ld total = 0;
  for (int i = 0; i < 110; i++)
    total += pos[i];
  printf ("%.20Lf\n", pos[p+20]/total);

  return 0;
}
