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

typedef pair<double, int> pdd;

int n;
vector<pdi> adj[1010];
bool vis[1010];

pdi prim () {
	for (int i = 1; i <= n; i++) vis[i] = false;
	pdi r = {0.0, 0};
	priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
	pq.push ({0.0, 1});
	while (!pq.empty()) {
		int v = pq.top().y;
		for (pdi p : adj[v])
			pq.push (p);
	}
}

int main ()
{
	int m;
	double t, w;
	int x, y;
	while (scanf ("%d %d %lf", &n, &m, &t) != EOF) {
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		for (int i = 0; i < q; i++) {
			scanf ("%d %d %lf", &x, &y, &w);
			adj[x].pb ({w, y});
			adj[y].pb ({w, x});
		}
	}

	return 0;
}
