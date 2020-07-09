#include <bits/stdc++.h>
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

const int N = 1e5+10;

int t;
int n, q;
int x, p;
set<pii> s;
int score[N];

int main () {
  scanf ("%d", &t);
  while (t--) {
    s.clear();
    scanf ("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
      score[i] = 0;
      s.insert ({0, i});
    }
    int ans = 0;
    int winner = 1;
    for (int i = 1; i <= q; i++) {
      scanf ("%d %d", &x, &p);
      s.erase ({-score[x], x});
      score[x] += p;
      s.insert ({-score[x], x});
      int now = s.begin()->y;
      if (winner != now) {
	winner = now;
	ans = i;
      }
      //printf ("winner: %d\n", winner);
    }
    //for (auto p : s)
    //printf ("%d %d\n", p.x, p.y);
    
    printf ("%d\n", ans);
  }
  
  return 0;
}
