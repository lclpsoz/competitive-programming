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

int n, m;
int a, b;
int st, en, cant_go;
int dist[1010];
vector<int> adj[1010];

void bfs () {
	queue<int> q;
	dist[st] = 0;
	q.push (st);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (dist[u] == INF && u != cant_go) {
				dist[u] = dist[v]+1;
				q.push (u);
			}
		}
	}
}

int main ()
{
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			dist[i] = INF;
		}
		for (int i = 0; i < m; i++) {
			scanf ("%d %d", &a, &b);
			adj[a].pb (b);
			adj[b].pb (a);
		}
		scanf ("%d %d %d", &st, &en, &cant_go);
		bfs();
		printf ("%d\n", dist[en]);
	}

	return 0;
}
