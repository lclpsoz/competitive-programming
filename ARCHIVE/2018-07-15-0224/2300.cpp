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

const int MAXN = 102;

int n, m;

bool vis[MAXN];
vector<int> adj[MAXN];

void dfs (int v) {
	if (vis[v]) return;
	vis[v] = true;
	for (int u : adj[v])
		dfs (u);
}

int main ()
{
	int a, b;
	int cnt = 1;
	while (scanf ("%d %d", &n, &m), n || m) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			vis[i] = false;
		}
		while (m--) {
			scanf ("%d %d", &a, &b);
			adj[a].pb (b);
			adj[b].pb (a);
		}
		dfs (1);
		bool ans = true;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				ans = false;
				break;
			}
		printf ("Teste %d\n", cnt++);
		printf ("%s\n\n", ans ? "normal" : "falha");
	}

	return 0;
}
