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

const int MAXN = 1e4+10;

int a, b;
priority_queue<pii> pq;
vector<pii> adj[MAXN];
bool vis[MAXN];

pii dijkstra () {
	pii r = {INF, INF};
	pq.push ({0, a});
	while (!pq.empty() && pq.top().y !=  b) {
		int v = pq.top().y;
		int w = pq.top().x;
		pq.pop();
		if (vis[v])
			continue;
		vis[v] = true;
		for (pii p : adj[v])
			pq.push({w-p.x, p.y});
	}
	if (!pq.empty())
		r.x = -pq.top().x;
	while (!pq.empty()) pq.pop();

	memset (vis, 0, sizeof (vis));
	pq.push ({0, b});
	while (!pq.empty() && pq.top().y !=  a) {
		int v = pq.top().y;
		int w = pq.top().x;
		pq.pop();
		if (vis[v])
			continue;
		vis[v] = true;
		for (pii p : adj[v])
			pq.push({w-p.x, p.y});
	}
	if (!pq.empty())
		r.y = -pq.top().x;

	return r;
}

int main ()
{
	int c, s;
	scanf ("%d %d %d %d", &c, &s, &a, &b);
	int x, y;
	for (int i = 0; i < s; i++) {
		scanf ("%d %d", &x, &y);
		adj[x].pb ({0, y});
		adj[y].pb ({1, x});
	}
	pii ans = dijkstra();
	// printf ("%d %d\n", ans.x, ans.y);
	if (ans.x == INF || ans.y == INF || ans.x == ans.y)
		printf ("Bibibibika\n");
	else if (ans.x < ans.y)
		printf ("Bibi: %d\n", ans.x);
	else
		printf ("Bibika: %d\n", ans.y);

	return 0;
}
