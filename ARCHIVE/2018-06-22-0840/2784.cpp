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

const int MAXN = 1005;

int n, m;
int st;
vector<pii> adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[MAXN];
bool vis[MAXN];

void dijkstra () {
	pq.push ({0, st});
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[st] = 0;
	while (!pq.empty()) {
		int v = pq.top().y;
		pq.pop();
		if (vis[v]) continue;
		vis[v] = true;
		for (pii p : adj[v]) {
			int w = p.x;
			int u = p.y;
			if (dist[v]+w < dist[u]) {
				pq.push ({dist[v]+w, u});
				dist[u] = dist[v]+w;
			}
		}
	}
}

int main ()
{
	int a, b, w;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d %d", &a, &b, &w);
		adj[a].pb ({w, b});
		adj[b].pb ({w, a});
	}
	cin >> st;
	int mini = INF;
	int maxi = -INF;
	for (pii p : adj[st])
		mini = min (mini, p.x);
	dijkstra();
	for (int i = 1; i <= n; i++)
		maxi = max (maxi, dist[i]);

	printf ("%d\n", maxi-mini);

	return 0;
}
