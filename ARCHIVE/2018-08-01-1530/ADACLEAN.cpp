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

const int MAXN = 1e6;

int t, n, k;
char arr[MAXN], aux[MAXN];
set<string> s;

int main ()
{
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &n, &k);
    scanf ("%s", arr);
    int l, r;
    l = 0;
    r = l+k;
    char c;
    while (r <= n) {
      c = arr[r];
      arr[r] = '\0';
      s.insert (arr+l);
      arr[r] = c;
      ++l;++r;
    }
    printf ("%ld\n", s.size());
    s.clear();
  }

  return 0;
}
