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

int n, t, m;
map<ll, int> love;

int main ()
{
  scanf ("%d", &n);
  ll x;
  int likes = 0;
  for (int j = 0; j < n; j++) {
    scanf ("%d %d", &t, &m);
    if (t == 1) {
      ++likes;
      for (int i = 0; i < m; i++) {
	scanf ("%lld", &x);
	love[x]++;
      }
    } else {
      for (int i = 0; i < m; i++) {
	scanf ("%lld", &x);
	love[x] = -1;
      }
    }
  }

  if (!likes) {
    ll aux = 1e18;
    printf ("%lld\n", aux-love.size());
  } else {
    //printf ("%d\n", likes);
    int ans = 0;
    for (auto p : love) {
      //printf ("%lld %d\n", p.x, p.y);
      if (p.y == likes)
	++ans;
    }
    printf ("%d\n", ans);
  }

  return 0;
}
