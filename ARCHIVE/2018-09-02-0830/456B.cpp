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

int two[]   = {1, 2, 4, 3};
int three[] = {1, 3, 4, 2};
int four[]  = {1, 4};
char str[N];

int main ()
{
  //int ans = 1;
  //int n;
  //scanf ("%d", &n);
  //ans += two[n%4] + three[n%4] + four[n%2];
  //printf ("%d\n", ans%5);
  scanf ("%s", str);
  int sz = strlen (str);
  int n;
  if (sz == 1) {
    n = str[sz-1]-'0';
  } else {
    n = (str[sz-2]-'0')*10 + (str[sz-1]-'0');
  }
  if (n%4 == 0)
    printf ("4\n");
  else
    printf ("0\n");
  
  return 0;
}
