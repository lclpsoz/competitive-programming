#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

char str[15010];

int main ()
{
  scanf ("%[^\n]", str);
  int s = strlen (str);
  for (int i = 0; i < s-2; i++)
    if ((i == 0 || str[i-1] == ' ') && str[i] == str[i+2] && str[i+1] == str[i+3]) {
      str[i] = str[i+1] = '_';
      ++i;
    }

  for (int i = 0; i < s; i++)
    if (str[i] != '_')
      putchar (str[i]);
  putchar ('\n');
  

  return 0;
}
