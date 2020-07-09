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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9 + 7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e4+10, K = 1e3+10;

int n, k, m, v, w;
queue<pii> pq;
bool vis[K];
vector<int> paths[K], vert[N];

int main () {
  scanf ("%d %d", &n, &k);
  for (int i = 1; i <= k; i++) {
    scanf ("%d", &m);
    while (m--) {
      scanf ("%d", &v);
      paths[i].push_back (v);
      vert[v].push_back (i);
    }
  }
  pq.push ({0, 1});
  while (!pq.empty() && pq.front().y != n) {
    w = pq.front().x; v = pq.front().y;
    //printf ("%d %d\n", w, v);
    pq.pop();
    for (int p : vert[v])
      if (!vis[p]) {
	vis[p] = true;
	for (int u : paths[p]) {
	  //printf ("(%d) ", u);
	  pq.push ({w+1, u});
	}
	//putchar ('\n');
      }
  }
  printf ("%d\n", pq.front().x);
  return 0;
}
