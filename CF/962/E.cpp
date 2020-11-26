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

using pp = pair<int, char>;

const int N = 2e5+100;
const int INF = 2e9;

int n;
int p;
char c;
int link[N], size[N];

int find (int a) {
  if (a == link[a])
    return a;
  return link[a] = find (link[a]);
}

bool same (int a, int b) {
  return find (a) == find (b);
}

void unite (int a, int b) {
  a = find (a);
  b = find (b);
  if (size[a] > size[b])
    swap (a, b);
  size[b] += size[a];
  link[a] = b;
}



ll func (vector<pp> &vec) {
  //cout << "Len: " << len (vec) << '\n';
  if (len (vec) <= 1)
    return 0;

  for (int i = 0; i <= len (vec); i++) {
    size[i] = 1;
    link[i] = i;
  }
  
  priority_queue<pair<ll, pii>> pq;
  int aux = -1;
  for (int i = 0; i < len (vec); i++)
    if (vec[i].y == 'P') {
      if (aux != -1)
	unite (aux, i);
      else
	aux = i;
      //cout << "  " << i-1 << '\n';
    }

  for (int i = 1; i < len (vec); i++)
    pq.push ({vec[i-1].x-vec[i].x, {i-1, i}});

  ll r = 0;
  while (!pq.empty()) {
    int u, v;
    u = pq.top().y.x;
    v = pq.top().y.y;
    ll w = pq.top().x;
    if (!same (u, v)) {
      r += -w;
      unite (u, v);
    }
    pq.pop();
  }

  int val = find (0);
  for (int i = 0; i < len (vec); i++)
    assert (val == find (i));
  
  return r;
}

int main () {
  vector<pp> byt, ber;
  int miniP = INF, maxiP = -INF;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d %c", &p, &c);
    if (c == 'P') {
      byt.push_back ({p, c});
      ber.push_back ({p, c});
      miniP = min (miniP, p);
      maxiP = max (maxiP, p);
    } else if (c == 'B')
      byt.push_back ({p, c});
    else if (c == 'R')
      ber.push_back ({p, c});
  }
  
  ll ans = 0;
  if (miniP != INF)
    ans += maxiP - miniP;
  //cout << ans << '\n';
  ans += func (byt);
  //cout << ans << '\n';
  ans += func (ber);
  //cout << ans << '\n';

  printf ("%lld\n", ans);

  return 0;
}
