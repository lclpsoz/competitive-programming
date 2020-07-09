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

///// GEOMETRY /////

using T = ld;

struct pt {
  T x, y;

  pt operator+ (pt p) {return {x+p.x, y+p.y};}
  pt operator- (pt p) {return {x-p.x, y-p.y};}
  pt operator* (T v) {return {x*v, y*v};}
  pt operator/ (T v) {return {x/v, y/v};}

  bool operator== (pt p) {return mp (x, y) == mp (p.x, p.y);}
  bool operator!= (pt p) {return !operator==(p);}
};

T dot (pt a, pt b) { return a.x*b.x + a.y*b.y; }

T isPerp (pt a);

T cross (pt a, pt b) { return a.x*b.y - a.y*b.x; }

// (+, 0, -) -> (left turn, collinear, right turn)
T orient (pt a, pt b, pt c) { return cross (b-a, c-a); }

int circTangents (pt o1, T r1, pt o2, T r2, bool inner, vector<pair<pt, pt>> &out) {
  if (inner) r2 = -r2;
  pt d = o2-o1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, q;
char arr[30][110];
ll pot[40], limites[40];

void fLim () {
  pot[0] = 1;
  for (int i = 1; pot[i-1] < 5e9; i++)
    pot[i] = pot[i-1]*n;
  limites[0] = 0;
  for (int i = 1; limites[i-1] < 5e9; i++)
    limites[i] = i*pot[i]+limites[i-1];
}

int main ()
{
  while (scanf ("%d %d", &n, &q), n || q) {
    ll qnt, x;
    for (int i = 0; i < n; i++)
      scanf ("%s", arr[i]);
    if (n == 1)
      while (q--) {
	scanf ("%lld", &x);
	printf ("%s\n", arr[0]);
      }
    else {
      fLim ();
      for (int i = 0; i < q; i++) {
	scanf ("%lld", &x);
	qnt = 1;
	while (limites[qnt] < x) ++qnt;
	x -= limites[qnt-1];
	//printf ("x: %d\n", x);
	if (x%qnt == 0)
	  printf ("%s\n", arr[(((x/qnt)-1+n)%n)]);
	else {
	  ll md = x%qnt;
	  x += md;
	  x = (x/qnt)-1+pot[md+1];
	  x %= pot[md+1];
	  x /= n;
	  printf ("%s\n", arr[x%n]);
	}
      }
    }
    //    for (int i = 0; i < 20; i++)
    //      printf ("%lld ", limites[i]);
    putchar ('\n');
  }

  return 0;
}
