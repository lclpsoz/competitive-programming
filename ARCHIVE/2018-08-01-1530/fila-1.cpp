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
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ld cross (point a, point b) {
  return (conj (a)*b).Y;
}

////////////////////////// Solution starts below. //////////////////////////////

typedef pair<point, point> line;

vector<point> v;
vector<pair<ld, point>> mids;

ld dist (line l, point a) {
  return ((cross (l.x - a, l.y - a))/abs(l.x-l.y));
}

point mid (point a, point b) {
  return ((a+b)/(ld)2);
}

void getL (ld r, point a, point b, line &l1, line &l2) {
  l1.x = l2.x = a;

  ld lad = hypot(a.X-b.X, a.Y-b.Y);
  ld th = acos(r / lad); // angle theta
  ld d = atan2(a.Y - b.Y, a.X - b.X); // Direcao do angulo de a pra b
  ld d1 = d + th; // Angulo direcao de l1
  ld d2 = d - th; // Angulo direcao de l2

  point t1, t2;
  t1 = {b.X + r * cos(d1), b.Y + r * sin(d1)};
  t2 = {b.X + r * cos(d2), b.Y + r * sin(d2)};
  
  l1.y = t1;
  l2.y = t2;
}

int main ()
{
  int n, x, y;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d %d", &x, &y);
    v.pb ({(ld)x, (ld)y});
  }
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++) {
      point m = mid (v[i], v[j]);
      mids.pb ({abs (m-v[i]), m});
    }

  ld ans = 1e18;
  for (auto p : mids) {
    ld maxi = -1;
    point far;
    for (int i = 0; i < n; i++) {
      ld aux = abs (p.y-v[i]);
      if (aux > maxi) {
	maxi = aux;
	far = v[i];
      }
    }
    // Get both tangents from circle in center far and point p.y
    line l1, l2;
    bool t1, t2;
    getL (p.x, p.y, far, l1, l2);
    t1 = t2 = true;
    for (int i = 0; i < n; i++) {
      //      printf ("%d\n", i);
      if (t1) 
	t1 = cmp (dist (l1, v[i]), p.x) <= 0;
      if (t2)
	t2 = cmp (dist (l2, v[i]), p.x) <= 0;
      if (!t1 && !t2)
	break;
    }
    if (t1 || t2)
      ans = min (ans, p.x);
  }
  printf ("%0.2Lf\n", ans);

  return 0;
}
