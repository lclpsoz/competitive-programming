#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

typedef pair<int, pii> piii;

const int MAXN = 1010;

int n, m;
vector<pii> arr[3];
int size[MAXN], link[MAXN];

void clear () {
  for (int i = 1; i <= n; i++) {
    size[i] = 1;
    link[i] = i;
  }
}

int find (int a) {
  if (a == link[a]) return a;
  return link[a] = find (link[a]);
}

bool same (int a, int b) {
  return find (a) == find (b);
}

void unite (int a, int b) {
  a = find (a);
  b = find (b);
  if (size[a] > size[b]) swap (a, b);
  size[b] += size[a];
  link[a] = b;
}

int main ()
{
  int v, u, w;
  int ins = 0;
  while (scanf ("%d %d", &n, &m) != EOF) {
    clear ();

    ll ans = 0;
    while (m--) {
      scanf ("%d %d %d", &v, &u, &w);
      if (w < 2000 && !same (v, u)) {
	unite (v, u);
	ans += w;
      }
      else if (w < 10000)
	arr[1].pb ({v, u});
      else
	arr[2].pb ({v, u});
    }

    while (!arr[1].empty()) {
      u = arr[1].back().x;
      v = arr[1].back().y;
      arr[1].pop_back();
      if (!same (u, v)) {
	unite (u, v);
	ans += 8977;
      }
    }
    while (!arr[2].empty()) {
      u = arr[2].back().x;
      v = arr[2].back().y;
      arr[2].pop_back();
      if (!same (u, v)) {
	unite (u, v);
	ans += 10923;
      }
    }
    printf ("Instancia %d\n", ++ins);
    printf ("%lld\n\n", ans);
  }

  return 0;
}
