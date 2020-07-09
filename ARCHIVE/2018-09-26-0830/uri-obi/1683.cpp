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

int n;
ll ans;
stack<pair<ll, ll>> q;
ll a[N];

int main ()
{
  while (scanf ("%d", &n), n) {
    ans = 0;
    for (int i = 0; i < n; i++)
      scanf ("%lld", &a[i]);
    while (!q.empty())
      q.pop();
    for (int i = n-1; i >= 0; i--) {
      //if (q.size()) printf (":: %lld %lld %lld\n", a[i], q.top().x, q.top().y);
      //else printf ("%lld EMPTY!\n", a[i]);
      if (q.empty()) {
	ans = max (ans, a[i]);
	q.push ({a[i], i});
      } else {
	if (a[i] > q.top().x)
	  q.push ({a[i], i});
	else if (a[i] < q.top().x) {
	  //printf ("> %lld %lld %lld\n", a[i], q.top().x, q.top().y);
	  int pos = 0;
	  while (!q.empty() && a[i] < q.top().x) {
	    auto p = q.top();
	    ans = max (ans, q.top().x*(q.top().y-i));
	    pos = p.y;
	    q.pop();
	  }
	  if (a[i] > 0)
	    q.push ({a[i], pos});
	}
      }
    }
    //printf ("STACK:\n");
    while (!q.empty()) {
      auto p = q.top();
      q.pop();
      //printf ("%lld %lld %lld\n", ans, p.x, p.y);
      ans = max (ans, p.x*(p.y+1));
    }
    printf ("%lld\n", ans);
  }

  return 0;
}
