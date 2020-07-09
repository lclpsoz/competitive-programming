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

using piiii = pair<pair<ll, int>, pair<int, int>>;
const int MAXX = 1e6+10;

int n, k, t;
int x, w;
deque<int> packs;
int wei[MAXX];
ll ans;
priority_queue<piiii, vector<piiii>, greater<piiii>> pq;

int main ()
{
  while (scanf ("%d %d", &n, &k) != EOF) {
    ++t;
    for (int i = 0; i < n; i++) {
      scanf ("%d %d", &x, &w);
      packs.pb (x);
      wei[x] = w;
      if (i > 0)
	pq.push ({{wei[packs[i-1]]*1LL*(x-packs[i-1]), wei[packs[i-1]]},
		{packs[i-1], x}});
    }
    ans = 0;
    while (n > k) {
      //printf ("%ld\n", pq.size());
      piiii aux = pq.top(); pq.pop();
      if (wei[aux.y.x] != aux.x.y || wei[aux.y.y] == -1)
	continue;
      //printf ("{%lld, %d}, {%d, %d}\n", aux.x.x, aux.x.y, aux.y.x, aux.y.y);
      ans += aux.x.x;
      wei[aux.y.y] += wei[aux.y.x];
      wei[aux.y.x] = -1;
      auto it = lower_bound (packs.begin(), packs.end(), aux.y.x);
      packs.erase (it); //Remove pack that was moved
      it = lower_bound (packs.begin(), packs.end(), aux.y.y);
      int p = it-packs.begin();
      //printf ("p: %d\n", p);
      if (p > 0)
	pq.push ({{wei[packs[p-1]]*1LL*(packs[p]-packs[p-1]), wei[packs[p-1]]},
	      {packs[p-1], packs[p]}});
      if ((p+1) < packs.size())
	pq.push ({{wei[packs[p]]*1LL*(packs[p+1]-packs[p]), wei[packs[p]]},
	      {packs[p], packs[p+1]}});
      --n;
      /*putchar ('[');
      for (int z : packs)
	printf ("%d ", z);
      putchar (']');
      putchar ('\n');*/
    }
    while (!pq.empty()) pq.pop();
    while (!packs.empty()) packs.pop_front();
    printf ("%lld\n", ans);
  }
  

  return 0;
}
