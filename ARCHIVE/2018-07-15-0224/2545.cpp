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
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 1010;

int n, m;
vector<int> dep[MAXN];
vector<int> adj[MAXN];
vector<int> topo;
bool vis[MAXN];

int dfs (int v, int prof) {
	// printf ("|%*d\n", 2*prof, v);
	int r = prof;
	bool tst = true;
	for (int u : dep[v])
		if (!vis[u]) {
			tst = false;
			break;
		}
	if (tst) {
		vis[v] = true;
		for (int u : adj[v])
			r = max (r, dfs (u, prof+1));
	} else
		r = 0;

	return r;
}

int main ()
{
	int a;
	while (scanf ("%d", &n) != EOF) {
		memset (vis, 0, sizeof (vis));
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &m);
			dep[i].clear();
			while (m--) {
				scanf ("%d", &a);
				dep[i].pb (a);
				adj[a].pb (i);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (dep[i].size() == 0)
				ans = max (ans, dfs (i, 1));
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				ans = 0;
				break;
			}
		printf ("%d\n", ans == 0 ? -1 : ans);
	}

	return 0;
}
