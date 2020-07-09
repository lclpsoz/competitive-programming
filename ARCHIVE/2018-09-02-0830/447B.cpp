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

const int N = 1e3+10;

char a[N];
int conv[30];

int main ()
{
  scanf ("%s", a);
  int k;
  scanf ("%d", &k);
  int maxi = 0;
  for (int i = 0; i < 26; i++) {
    scanf ("%d", &conv[i]);
    maxi = max (maxi, conv[i]);
  }
  ll acu = 0;
  for (int i = 0; a[i] != '\0'; i++)
    acu += (i+1)*conv[a[i]-'a'];
  int n = strlen (a);
  for (int i = n+1; i <= n+k; i++)
    acu += i*maxi;
  printf ("%lld\n", acu);

  return 0;
}
