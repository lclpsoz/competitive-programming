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
vector<int> v;
int x, y;
int l, r;

int main ()
{
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d %d", &x, &y);
    l += x; r += y;
    v.pb (x-y);
  }
  int ans = abs (l-r);
  int pos = 0;
  for (int i = 0; i < n; i++) {
    int aux = abs ((l-v[i])-(r+v[i]));
    //printf ("%d\n", aux);
    if (aux > ans) {
      ans = aux;
      pos = i+1;
    }
  }
  printf ("%d\n", pos);
  
  return 0;
}
