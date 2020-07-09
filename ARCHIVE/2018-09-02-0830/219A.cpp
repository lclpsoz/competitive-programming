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

int k;
char str[1010];
int a[100];

int main ()
{
  scanf ("%d %s", &k, str);
  int sz = strlen (str);
  for (int i = 0; i < sz; i++)
    a[str[i]-'a']++;
  bool test = true;
  for (int i = 0; i < 26; i++)
    if (a[i] && a[i]%k) {
      test = false;
      break;
    }
  if (!test)
    printf ("-1\n");
  else {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < 26; j++)
	for (int l = 0; l < a[j]/k; l++)
	  printf ("%c", j+'a');
    putchar ('\n');
  }
  
  return 0;
}
