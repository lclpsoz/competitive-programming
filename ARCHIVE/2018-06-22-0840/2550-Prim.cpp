// Prim's
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
int a, b, w;
vector<pii> adj[MAXN];
bool vis[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main ()
{
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < m; i++) {
			scanf ("%d %d %d", &a, &b, &w);
			adj[a].pb ({w, b});
			adj[b].pb ({w, a});
		}
		ll ans = 0;
		vis[1] = true;
		for (pii p : adj[1])
			pq.push ({p.x, p.y});
		while (!pq.empty()) {
			int v = pq.top().y;
			int w = pq.top().x;
			pq.pop();
			if (vis[v]) continue;
			vis[v] = true;
			ans += w;
			for (pii p : adj[v])
				if (!vis[p.y])
					pq.push ({p.x, p.y});
		}

		for (int i = 1; i <= n; i++) {
			if (!vis[i]) ans = -1;
			vis[i] = false;
			adj[i].clear();
		}
		if (ans == -1)
			printf ("impossivel\n");
		else
			printf ("%lld\n", ans);
	}

	return 0;
}
