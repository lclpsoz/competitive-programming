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

int n, m;
char a[14], b[14];
map<string, string> d1, d2;

int main ()
{
  cin >> n >> m;
  while (m--) {
    scanf ("%s %s", a, b);
    d1[a] = b;
    d2[b] = a;
  }
  while (n--) {
    scanf ("%s", a);
    string str = a;
    if (d1.count(a)) {
      if (d1[a].length() < str.length())
	cout << d1[a] << ' ';
      else
	cout << str << ' ';
    } else {
      if (d2[a].length() <= str.length())
	cout << d2[a] << ' ';
      else
	cout << str << ' ';
    }
  }
  putchar ('\n');

  return 0;
}
