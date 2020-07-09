#include <bits/stdc++.h>
#define len(x) ((int)(x).size())
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

const ld EPS = 1e-9;

pdd e, am;
ld xx;
ld d;
bool inv = false;

ld operator- (const pdd &a, const pdd &b) {
  pdd x = {a.x-b.x, a.y-b.y};
  //cout << "\n||" << a.x << ' '<< a.y << ' ' << b.x << ' ' << b.y << '\n';
  return sqrt ((x.x*x.x) + (x.y*x.y));
}

bool check (ld a, ld b, ld c) {
  if (a > (b+c) || b > (a+c) || c > (a+b)) return false;
  return true;
}

ld func (ld mid) {
  pdd nv = {e.x+sinl (mid)*xx, e.y+cosl (mid)*xx};
  //cout << "\n::" << nv.x << ' ' << nv.y << '\n';
  return nv-am;
}

ld bb (ld x, ld y) {
  int cont = 1e6;
  if (func ((ld) 0.01) <= func ((ld) 3.0)) {
    while (cont--) {
      ld mid = (x+y)/2.0;
      //cout << x << ' ' << y << ' ' << mid << " | " << func (mid) << '\n';

      ld ff = func (mid);
      if (ff > d+EPS)
	y = mid-EPS;
      else
	x = mid;
    }
  } else {
    inv = true;
    while (cont--) {
      ld mid = (x+y)/2.0;
      //cout << '|' << x << ' ' << y << ' ' << mid << " | " << func (mid) << '\n';

      ld ff = func (mid);
      if (ff < d+EPS)
	y = mid;
      else
	x = mid+EPS;
    }
  }

  return x;
}

int main(){
  cin >> am.x >> am.y >> e.x >> e.y >> d;
  //scanf ("%Lf %Lf %Lf %Lf %Lf", &am.x, &am.y, &e.x, &e.y, &d);
  xx = e-am;
  if (!check (d, xx, xx)) {
    cout << "NO\n";
    //printf ("NO\n");
  } else {
    cout << "YES\n";
    //printf ("YES\n");
    ld ang = bb (0, acos((ld)-1));
    pdd p1 = {sinl (ang)*xx, cosl (ang)*xx};
    pdd p2 = {(sinl(2*acos((ld)-1)-ang))*xx, ((cosl(2*acos((ld)-1)-ang)))*xx};
    if (inv) {
      p1.x = -p1.x;
      p1.y = -p1.y;
      p2.x = -p2.x;
      p2.y = -p2.y;
    }
    cout << fixed << setprecision(9) << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << '\n';
    //printf ("%.8Lf %.8Lf %.8Lf %.8Lf\n", p1.x, p1.y, p2.x, p2.y);
  }
    
  return 0;
}
