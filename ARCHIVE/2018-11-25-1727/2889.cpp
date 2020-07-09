#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using pp = pair<pii, int>;

bool func (pp &a, pp &b) {
  return (a.x.x > b.x.x ||
	  (a.x.x == b.x.x && (a.x.y > b.x.y ||
			      (a.x.y == b.x.y &&
			       a.y < b.y))));
}


pp vec[(int)1e6+10];
int n, m;
int t1, t2, p1, p2;
vector<pii> qnt;
int main () {
  int maxi = -1;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    qnt.push_back ({0, i});
  while (scanf ("%d", &m), m) {
    for (int i = 0; i < n; i++)
      vec[i] =  {{0, 0}, i};
    while (m--) {
      scanf ("%d %d %d %d", &t1, &p1, &t2, &p2);
      --t1; --t2;
      if (p1 == p2) {
	vec[t1].x.x++;
	vec[t2].x.x++;
	vec[t1].x.y += p1;
	vec[t2].x.y += p2;
      } else {
	if (p1 < p2) {
	  swap (p1, p2);
	  swap (t1, t2);
	}
	//printf ("> %d %d\n", t1, t2);
	vec[t1].x.x += 3;
	vec[t1].x.y += p1;
	//printf ("> %d %d %d\n", vec[t1].x.x, vec[t1].x.y, vec[t1].y);
      }
    }
    pp sec = {{0, 0}, 0};
    for (int i = 0; i < n; i++)
      if (func (vec[i], sec)) {
	//printf ("%d %d %d\n", vec[i].x.x, vec[i].x.y, vec[i].y);
	sec = vec[i];
      }
    //printf ("|%d %d\n", sec.y, len (vec));
    vec[sec.y] = {{-1, -1}, 1e9};
    sec = {{0, 0}, 0};
    for (int i = 0; i < n; i++)
      if (func (vec[i], sec))
	sec = vec[i];
    //printf ("||%d %d\n", sec.y, len (vec));
    
    qnt[sec.y].x++;
    maxi = max (maxi, qnt[sec.y].x);
  }
  int val = qnt[0].x;
  if (val < maxi) {
      printf ("N\n");
      return 0;
    }
  printf ("Y\n");

  return 0;
}
