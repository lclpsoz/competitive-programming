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

vector<pii> adj[MAXN];
bool hosp[MAXN];
int dist[MAXN];
int n, m, q;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra (int st) {
	vector<bool> vis(n+1, 0);
	pq.push ({0, st});
	dist[st] = 0;
	while (!pq.empty()) {
		int v = pq.top().y;
		int w = pq.top().x;
		// printf ("    %d\n", w);
		pq.pop();
		if (vis[v]) continue;
		vis[v] = true;
		for (pii u : adj[v])
			if (u.x+w < dist[u.y]) {
				dist[u.y] = u.x+w;
				pq.push ({u.x+w, u.y});
			}
	}
}

int main ()
{
	int a, b, w;
	for (int i = 1; i <= MAXN; i++) dist[i] = INF;
	while (scanf ("%d %d %d", &n, &m, &q) != EOF) {
		while (m--) {
			scanf ("%d %d %d", &a, &b, &w);
			adj[a].pb ({w, b});
			adj[b].pb ({w, a});
		}
		for (int i = 0; i < q; i++) {
			scanf ("%d", &a);
			hosp[a] = true;
		}
		int ans = -1;
		for (int i = 1; i <= n; i++)
			if (hosp[i])
				dijkstra (i);
		for (int i = 1; i <= n; i++) {
			ans = max (dist[i], ans);
			dist[i] = INF;
			adj[i].clear();
			hosp[i] = false;
		}

		cout << ans << '\n';
	}

	return 0;
}
