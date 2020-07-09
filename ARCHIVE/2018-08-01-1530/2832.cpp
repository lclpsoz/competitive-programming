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

const int N = 1e6+10;

int n, f;
int arr[N];
vector<pii> v;

ll check (int days) {
  ll r = 0;
  for (pii p : v)
    r += p.y*(days/p.x);

  return r;
}

int bb () {
  int l = 1, r = 1e8;
  while (l < r) {
    int mid = (l+r)/2;
    ll val = check (mid);
    if (val < f)
      l = mid+1;
    else
      r = mid;
  }
  
  return l;
}

int main ()
{
  int x;
  scanf ("%d %d", &n, &f);
  while (n--) {
    scanf ("%d", &x);
    ++arr[x];
  }
  for (int i = 1; i <= 1e6; i++)
    v.pb ({i, arr[i]});

  printf ("%d\n", bb());

  return 0;
}
