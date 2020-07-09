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

char str[110];

bool verif (int x) {
  //printf ("%d\n", x);
  char s[10];
  vector<int> v;
  if (x == 0)
    v.pb (0);
  else
    while (x) {
      v.pb (x%10);
      x/=10;
    }
  int p = 0;
  for (int i = v.size()-1; i >= 0; i--)
    s[p++] = v[i]+'0';
  s[p] = '\0';
  int n = p;
  p = 0;
  //printf ("s: %s\n", s);
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == s[p])
      ++p;
    //printf (" %c %c | %d\n", str[p], s[p]p);
    if (p == n)
      return true;
  }
  return false;
}

int sol () {
  for (int i = 0; i < 1010; i+=8) {
    if (verif (i))
      return i;
  }
  return -1;
}

int main ()
{
  scanf ("%s", str);
  int x = sol ();
  if (x == -1)
    printf ("NO\n");
  else
    printf ("YES\n%d\n", x);

  return 0;
}
