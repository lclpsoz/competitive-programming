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

int n, m;
deque<int> v;

void prt (int p) {
  if (v.size() > 1)
    printf ("%d ", v[p]);
  else
    printf ("%d", v[p]);
  if (p == 0)
    v.pop_front();
  else
    v.pop_back();
}

int main ()
{
  cin >> n;
  bool tst = false;
  while (n--) {
    cin >> m;
    while (m--) {
      int x;
      scanf ("%d", &x);
      if (x&1 == 1)
	v.pb (x);
    }
    sort (v.begin(), v.end());
    if (!v.empty()) {
      bool state = true;
      while (!v.empty()) {
	if (state)
	  prt (v.size()-1);
	else
	  prt (0);
	state = !state;
      }
      tst = true;
    }
    putchar ('\n');
  }

  return 0;
}
