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
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 2e5+10;

int n, m, k;
vector<vector<int>> ans;
bool vis[MAXN];
vector<pii> adj[MAXN];
vector<int> aux;

void func (int v) {
	if (ans.size() == k)
		return;
	vis[v] = true;
	bool tst = false;
	for (pii u : adj[v])
		if (!vis[u.x]) {
			tst = true;
			aux[u.y] = 1;
			func (u.x);
			aux[u.y] = 0;
		}
	if (!tst) ans.pb (aux);
	vis[v] = false;
}

int main ()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		aux.pb (0);
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &x, &y);
		--x; --y;
		adj[x].pb ({y, i});
		adj[y].pb ({x, i});

	}
	func (0);
	cout << ans.size() << '\n';
	for (vector<int> &xx : ans) {
		for (int x : xx)
			printf ("%d", x);
		putchar ('\n');
	}

  return 0;
}
